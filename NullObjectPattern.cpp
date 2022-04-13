#include "NullObjectPattern.h"

using namespace loggers;

int main()
{
	SomeTask task1(new ConsoleLogger);
	SomeTask task2(new FileLogger("logs.txt"));
	SomeTask task3(new ApiLogger("loggingsite.com/api/logs"));
	SomeTask task4;
	task1.execute();
	task2.execute();
	task3.execute();
	task4.execute();

	return 0;
}