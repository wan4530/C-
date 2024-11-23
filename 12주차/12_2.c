#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {

	time_t current;
	struct tm* timeinfo;

	int year, month, day;
	char* WEEK[] = { "일", "월","화","수","목","금","토" };

	printf("Enter YYYY MM DD : ");
	scanf("%d %d %d", &year, &month, &day);

	current = time(NULL);
	timeinfo = localtime(&current);

	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	mktime(timeinfo);

	printf("%d %d %d -> %s\n", year, month, day, WEEK[timeinfo->tm_wday]);
	return 0;
}