#ifndef CLONE_FACTORY_H
#define CLONE_FACTORY_H

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



template <class AbstractProduct,
		  class ProductCloner = AbstractProduct* (*)(const AbstractProduct*),
		  template<class> class FactoryErrorPolicy = DefaultCloneFactoryError>
class CloneFactory : public FactoryErrorPolicy<AbstractProduct>
	{
	public:
	AbstractProduct* clone(const AbstractProduct* prototype)
		{
		std::type_index index{typeid(prototype)};
		auto it = id2Cloner.find(index);
		if (it != id2Cloner.end())
			return it -> second(prototype);
		return this -> onUnknownType(prototype);
		}
	bool registerProduct(const std::type_index& typeId, ProductCloner creator)
		{
		std::pair<std::type_index, ProductCloner> insertingPair(typeId, creator);
		return id2Cloner.insert(insertingPair).second;
		}
	bool unregisterProduct(const std::type_index& typeId)
		{
		return id2Cloner.erase(typeId) == 1;
		}

	static CloneFactory& instance()
		{
		static CloneFactory instance_;
		return instance_;
		}

	private:
	CloneFactory() = default;

	private:
	std::unordered_map<std::type_index, ProductCloner> id2Cloner;
	};

#endif // CLONE_FACTORY_H
