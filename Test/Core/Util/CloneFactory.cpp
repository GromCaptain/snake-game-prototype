#include <gtest/gtest.h>
#include "Core/Util/CloneFactory.h"

class Base
	{
	public:
	Base(int value): value_(value), id_(currId++) {}
	Base(const Base& other): value_(other.value_), id_(currId++) {}
	virtual ~Base() {}

	int value() const { return value_; }
	int id() const { return id_; }

	private:
	static int currId;

	private:
	int value_;
	int id_;
	};

int Base::currId = 1;

class FirstDerived : public Base
	{
	public:
	FirstDerived(int value, char c): Base(value), c_(c) {}
	FirstDerived(const FirstDerived& other): Base(other), c_(other.c_) {}

	int c() const { return c_; }

	private:
	char c_;
	};

class SecondDerived : public Base
	{
	public:
	SecondDerived(int value, double d): Base(value), d_(d) {}
	SecondDerived(const SecondDerived& other): Base(other), d_(other.d_) {}

	double d() const { return d_; }

	private:
	double d_;
	};

class ThirdDerived : public FirstDerived
	{
	public:
	ThirdDerived(int value, char c, int i): FirstDerived(value, c), i_(i) {}
	ThirdDerived(const ThirdDerived& other): FirstDerived(other), i_(other.i_) {}

	int i() const { return i_; }

	private:
	int i_;
	};

namespace
{
bool baseRegistered = CloneFactory<Base>::instance().registerProduct<Base>();
bool firstDerRegistered = CloneFactory<Base>::instance().registerProduct<FirstDerived>();
bool secondDerRegistered = CloneFactory<Base>::instance().registerProduct<SecondDerived>();
bool thirdDerRegistered = CloneFactory<Base>::instance().registerProduct<ThirdDerived>();
}

CloneFactory<Base>& getFactory()
	{
	return CloneFactory<Base>::instance();
	}

std::shared_ptr<Base> getClone(std::shared_ptr<Base> prototype)
	{
	const Base* prototypePtr = prototype.get();
	return std::shared_ptr<Base>(getFactory().clone(prototypePtr));
	}

TEST(CloneFactory, CloneBase_CopyingFields)
	{
	auto prototype = std::shared_ptr<Base>(new Base(3));
	auto clone = getClone(prototype);
	EXPECT_EQ(3, clone -> value());
	}

TEST(CloneFactory, CloneBase_ClonedByCopyConstructor)
	{
	auto prototype = std::shared_ptr<Base>(new Base(3));
	auto clone = getClone(prototype);
	EXPECT_NE(prototype -> id(), clone -> id());
	}

TEST(CloneFactory, FirstDerived_CorrectClass)
	{
	auto prototype = std::shared_ptr<Base>(new FirstDerived(5, 'x'));
	auto clone = getClone(prototype);
	auto castedClone = std::dynamic_pointer_cast<FirstDerived>(clone);
	auto thirdDerCastedClone = std::dynamic_pointer_cast<ThirdDerived>(clone);
	EXPECT_TRUE(castedClone != nullptr);
	EXPECT_TRUE(thirdDerCastedClone == nullptr);
	}

TEST(CloneFactory, FirstDerived_CopyingFields)
	{
	auto prototype = std::shared_ptr<Base>(new FirstDerived(5, 'x'));
	auto clone = getClone(prototype);
	auto castedClone = std::dynamic_pointer_cast<FirstDerived>(clone);
	EXPECT_EQ(5, castedClone -> value());
	EXPECT_EQ('x', castedClone -> c());
	}

TEST(CloneFactory, FirstDerived_ClonedByCopyConstructor)
	{
	auto prototype = std::shared_ptr<Base>(new FirstDerived(5, 'x'));
	auto clone = getClone(prototype);
	EXPECT_LT(prototype -> id(), clone -> id());
	}

TEST(CloneFactory, SecondDerived_CorrectClass)
	{
	auto prototype = std::shared_ptr<Base>(new SecondDerived(5, 3.14));
	auto clone = getClone(prototype);
	auto castedClone = std::dynamic_pointer_cast<SecondDerived>(clone);
	EXPECT_TRUE(castedClone != nullptr);
	}

TEST(CloneFactory, SecondDerived_CopyingFields)
	{
	auto prototype = std::shared_ptr<Base>(new SecondDerived(5, 3.14));
	auto clone = getClone(prototype);
	auto castedClone = std::dynamic_pointer_cast<SecondDerived>(clone);
	EXPECT_EQ(5, castedClone -> value());
	EXPECT_EQ(3.14, castedClone -> d());
	}

TEST(CloneFactory, SecondDerived_ClonedByCopyConstructor)
	{
	auto prototype = std::shared_ptr<Base>(new SecondDerived(5, 3.14));
	auto clone = getClone(prototype);
	EXPECT_LT(prototype -> id(), clone -> id());
	}

TEST(CloneFactory, ThirdDerived_CorrectClass)
	{
	auto prototype = std::shared_ptr<Base>(new ThirdDerived(5, '%', 42));
	auto clone = getClone(prototype);
	auto castedClone = std::dynamic_pointer_cast<ThirdDerived>(clone);
	EXPECT_TRUE(castedClone != nullptr);
	}

TEST(CloneFactory, ThirdDerived_CopyingFields)
	{
	auto prototype = std::shared_ptr<Base>(new ThirdDerived(5, '%', 42));
	auto clone = getClone(prototype);
	auto castedClone = std::dynamic_pointer_cast<ThirdDerived>(clone);
	EXPECT_EQ(5, castedClone -> value());
	EXPECT_EQ('%', castedClone -> c());
	EXPECT_EQ(42, castedClone -> i());
	}

TEST(CloneFactory, ThirdDerived_ClonedByCopyConstructor)
	{
	auto prototype = std::shared_ptr<Base>(new ThirdDerived(5, '%', 42));
	auto clone = getClone(prototype);
	EXPECT_LT(prototype -> id(), clone -> id());
	}
