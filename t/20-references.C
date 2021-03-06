
#include <perl++/perl++.h>
#define WANT_TEST_EXTRAS
#include <tap++/tap++.h>

using namespace perl;
using namespace TAP;

int main() {
//	TEST_START(17);
	plan(25);
	Interpreter universe;

	{
	Ref<Scalar> value = universe.value_of(1).take_ref();

	is(*value, 1, "*value == 1");
	is(*value, 1u, "*value == 1u");
	is(*value, 1l, "*value == 1l");
	is(*value, "1", "*value == \"1\"");
	is(*value, about(1.0), "*value == 1.0");
	isnt(*value, about(2.0), "*value != 2.0");
	is(*value, about(1.0f), "*value == 1.0f");
	isnt(*value, about(2.0f), "*value != 2.0f");

	*value = 2;
	note("*value = 2");

	is(*value, 2, "*value == 2");
	}

	{
	Ref<Integer> value = universe.value_of(1).take_ref();
	is(*value, 1, "*value == 1");
	is(*value, 1u, "*value == 1u");
	is(*value, 1l, "*value == 1l");

	is(*value, about(1.0), "*value == 1.0");
	isnt(*value, about(2.0), "*value != 2.0");
	is(*value, about(1.0f), "*value == 1.0f");
	isnt(*value, about(2.0f), "*value != 2.0f");

	*value = 2;
	note("*value = 2");

	is(*value, 2, "*value == 2");
	}

	{
	Ref<Number> value = universe.value_of(1.0).take_ref();
	is(*value, 1, "*value == 1");
	is(*value, 1u, "*value == 1u");
	is(*value, 1l, "*value == 1l");

	is(*value, about(1.0), "*value == 1.0");
	isnt(*value, about(2.0), "*value != 2.0");
	is(*value, about(1.0f), "*value == 1.0f");
	isnt(*value, about(2.0f), "*value != 2.0f");

	*value = 2.0;
	note("*value = 2");

	is(*value, about(2.0), "*value == 2");
	}
//	TEST_END;
	return exit_status();
}
