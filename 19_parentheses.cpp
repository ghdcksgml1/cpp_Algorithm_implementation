#include <stdbool.h>

int s_open = 0;

bool solution(const char* s) {
	bool answer = true;

	while (*s != 0) {
		if ((s_open == 0 && *s == ')') || s_open < 0) {
			return false;
		}
		else if (*s == '(') {
			s_open++;
		}
		else if (*s == ')') {
			s_open--;
		}
		s++;
	}
	return s_open != 0 ? false : true;
}