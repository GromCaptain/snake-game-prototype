#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <memory>

template <typename ResultType, typename... Args> class FunctorImpl
	{
	public:
	virtual ResultType operator()(Args... args) = 0;
	virtual FunctorImpl* clone() const = 0;
	virtual ~FunctorImpl() {}
	};

template <typename Fun, class ResultType, typename... Args> class FunctorHandler
	: public FunctorImpl<ResultType, Args...>
	{
	public:
	FunctorHandler(const Fun& f): fun(f) {}
	FunctorHandler* clone() const { return new FunctorHandler(*this); }

	ResultType operator()(Args... args) { return fun(args...); }

	private:
	Fun fun;
	};

template <typename PointerToObj, typename PointerToMemFunction, class ResultType, typename... Args> class MemHandler
	: public FunctorImpl<ResultType, Args...>
	{
	public:
	MemHandler(const PointerToObj& obj, PointerToMemFunction mf): pObj(obj), memberFun(mf) {}
	FunctorImpl<ResultType, Args...>* clone() const { return new MemHandler(*this); }

	ResultType operator()(Args... args) { return ((*pObj).*memberFun)(args...); }

	private:
	PointerToObj pObj;
	PointerToMemFunction memberFun;
	};

template <typename ResultType, typename... Args> class Functor
	{
	public:
	Functor() {}
	Functor(const Functor& f): pImpl_(f.pImpl_) {}
	Functor& operator=(const Functor& f) { pImpl_ = f.pImpl_; return *this; }

	template<typename Fun> Functor(const Fun& fun): pImpl_(new FunctorHandler<Fun, ResultType, Args...>(fun)) {}
	template<typename PointerToObj, typename PointerToMemFunction> Functor(PointerToObj pObj, PointerToMemFunction pMemberFunc):
		pImpl_(new MemHandler<PointerToObj, PointerToMemFunction, ResultType, Args...>(pObj, pMemberFunc)) {}

	typedef FunctorImpl<ResultType, Args...> Impl;
	explicit Functor(std::shared_ptr<Impl> pImpl): pImpl_(pImpl) {}

	ResultType operator()(Args... args) { return (*pImpl_)(args...); }

	private:
	std::shared_ptr<Impl> pImpl_;
	};

template <typename ResultType, typename Bound, typename... ArgsTail> class BinderFirst
	: public FunctorImpl<ResultType, ArgsTail...>
	{
	public:
	typedef Functor<ResultType, Bound, ArgsTail...> Incoming;
	BinderFirst(const Incoming& f, Bound b): fun(f), bound(b) {}
	BinderFirst* clone() const { return new BinderFirst(*this); }
	ResultType operator()(ArgsTail... args) { return fun(bound, args...); }

	private:
	Incoming fun;
	Bound bound;
	};

template <typename ResultType, typename Bound, typename... ArgsTail>
	Functor<ResultType, ArgsTail...> bindFirst(const Functor<ResultType, Bound, ArgsTail...> f, Bound bound)
	{
	typedef Functor<ResultType, ArgsTail...> Outgoing;
	typedef BinderFirst<ResultType, Bound, ArgsTail...> Binder;
	return Outgoing(std::shared_ptr<typename Outgoing::Impl>(new Binder(f, bound)));
	}

#endif
