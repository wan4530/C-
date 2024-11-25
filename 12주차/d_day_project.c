#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <time.h>

void d_day(int year, int month, int day) {
	time_t current;
	time_t userDay;
	int diff;
	struct tm* timeinfo;
	current = time(NULL);
	timeinfo = localtime(&current);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	userDay = mktime(timeinfo);

	diff = difftime(userDay, current);
	diff = diff / (60 * 60 * 24);
	printf("%d %d %d는 오늘로 부터 %d일 후(-전) 입니다.", year, month, day, diff);

}

int main(int argc, char* argv[]) {

	d_day(atoi(argv[1]),atoi(argv[2]), atoi(argv[3]));

	return 0;
}