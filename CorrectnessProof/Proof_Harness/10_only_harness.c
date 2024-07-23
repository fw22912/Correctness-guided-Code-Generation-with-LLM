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

void combined_proof_harness() {
  proof_harness_matchStar();
  proof_harness_isMatch();
  proof_harness_main();
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

