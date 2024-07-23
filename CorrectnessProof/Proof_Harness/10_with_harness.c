#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char* s, char* p);
bool matchStar(char ch, char* s, char* p);

/*
Uses Rob pikes Regexp matcher - https://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html
Implementation:
    // match: search for regexp anywhere in text 
    int match(char *regexp, char *text)
    {
        if (regexp[0] == '^')
            return matchhere(regexp+1, text);
        do {  
            if (matchhere(regexp, text))
                return 1;
        } while (*text++ != '\0');
        return 0;
    }
*/

bool matchStar(char ch, char* s, char* p) {
  do {
    if (isMatch(s, p))
      return true;
  } while (*s != '\0' && (*s++ == ch || ch == '.'));

  return false;
}

bool isMatch(char* s, char* p) {
  if (*p == '\0')
    return *s == '\0';

  if (p[1] == '*')
    return matchStar(p[0], s, p + 2);

  if (*s != '\0' && (p[0] == '.' || *p == *s)) {
    return isMatch(s + 1, p + 1);
  }

  return false;
}

void proof_harness_matchStar() {
  char *s = (char *)malloc(21 * sizeof(char));
  __CPROVER_assume(s != NULL);
  char *p = (char *)malloc(31 * sizeof(char));
  __CPROVER_assume(p != NULL);
  char ch;
  __CPROVER_assume(strlen(s) <= 20);
  __CPROVER_assume(strlen(p) <= 30);
  __CPROVER_assume(s[0] != '\0');
  __CPROVER_assume(p[0] != '\0');
  __CPROVER_assume(p[1] == '*');
  __CPROVER_assume(ch == p[0] || ch == '.');
  bool result = matchStar(ch, s, p + 2);
  free(s);
  free(p);
}

void proof_harness_isMatch() {
  char *s = (char *)malloc(21 * sizeof(char));
  __CPROVER_assume(s != NULL);
  char *p = (char *)malloc(31 * sizeof(char));
  __CPROVER_assume(p != NULL);
  __CPROVER_assume(strlen(s) <= 20);
  __CPROVER_assume(strlen(p) <= 30);
  bool result = isMatch(s, p);
  free(s);
  free(p);
}

void proof_harness_main() {
  char *s = (char *)malloc(21 * sizeof(char));
  __CPROVER_assume(s != NULL);
  char *p = (char *)malloc(31 * sizeof(char));
  __CPROVER_assume(p != NULL);
  __CPROVER_assume(strlen(s) <= 20);
  __CPROVER_assume(strlen(p) <= 30);
  isMatch(s, p);
  free(s);
  free(p);
}

void combined_proof_harness() {
  proof_harness_matchStar();
  proof_harness_isMatch();
  proof_harness_main();
}