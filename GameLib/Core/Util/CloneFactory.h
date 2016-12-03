#ifndef CLONE_FACTORY_H
#define CLONE_FACTORY_H

#include <memory>
#include <exception>
#include <typeindex>
#include <unordered_map>

template <class AbstractProduct> class DefaultCloneFactoryError
	{
	public:
	class Exception : public std::exception
		{
		public:
		Exception(const std::type_index& unknownId): unknownId_(unknownId) {}
		virtual const char* what() const noexcept { return "Trying to clone object of unknown type."; }
		const std::type_index unknownId() const noexcept { return unknownId_; }

		private:
		std::type_index unknownId_;
		};

	protected:
	AbstractProduct* onUnknownType(const AbstractProduct* prototype)
		{
		std::type_index typeId {typeid(prototype)};
		throw Exception(typeId);
		}
	};



template <class AbstractProduct, template<class> class FactoryErrorPolicy = DefaultCloneFactoryError>
class CloneFactory : public FactoryErrorPolicy<AbstractProduct>
	{
	public:
	AbstractProduct* clone(const AbstractProduct* prototype)
		{
		std::type_index index{typeid(*prototype)};
		auto it = id2Cloner.find(index);
		if (it != id2Cloner.end())
			return it -> second -> clone(prototype);
		return this -> onUnknownType(prototype);
		}

	template <class ConcreteProduct> bool registerProduct()
		{
		std::type_index index{typeid(ConcreteProduct)};
		ClonerPtr cloner {new ConcreteCloner<ConcreteProduct>()};
		return id2Cloner.emplace(index, cloner).second;
		}

	template <class ConcreteProduct> bool unregisterProduct()
		{
		std::type_index index{typeid(ConcreteProduct)};
		return id2Cloner.erase(index) == 1;
		}

	static CloneFactory& instance()
		{
		static CloneFactory instance_;
		return instance_;
		}

	private:
	CloneFactory() {}

	private:
	class AbstractCloner
		{
		public:
		virtual ~AbstractCloner() {}
		virtual AbstractProduct* clone(const AbstractProduct *prototype) = 0;
		};

	template <class ConcreteProduct> class ConcreteCloner : public AbstractCloner
		{
		AbstractProduct* clone(const AbstractProduct *prototype) override
			{
			const ConcreteProduct* castedPrototype = dynamic_cast<ConcreteProduct*>(const_cast<AbstractProduct*>(prototype));
			return new ConcreteProduct(*castedPrototype);
			}
		};

	using ClonerPtr = std::shared_ptr<AbstractCloner>;
	std::unordered_map<std::type_index, ClonerPtr> id2Cloner;
	};

#endif // CLONE_FACTORY_H
