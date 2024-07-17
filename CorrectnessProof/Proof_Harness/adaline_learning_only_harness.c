void proof_harness_adaline_get_weights_str() {
  struct adaline ada;
  ada.num_weights = 3;
  ada.weights = (double *)malloc(ada.num_weights * sizeof(double));
  assert(ada.weights != NULL);
  ada.weights[0] = 1.0;
  ada.weights[1] = 2.0;
  ada.weights[2] = 3.0;
  char *out = adaline_get_weights_str(&ada);
  assert(strcmp(out, "<1.0000,2.0000,3.0000>") == 0);
  free(ada.weights);
}

void proof_harness_test1() {
  double eta = 0.1;
  test1(eta);
}

void proof_harness_adaline_predict() {
  struct adaline ada;
  ada.num_weights = 3;
  ada.weights = (double *)malloc(ada.num_weights * sizeof(double));
  assert(ada.weights != NULL);
  ada.weights[0] = 1.0;
  ada.weights[1] = 2.0;
  ada.weights[2] = 3.0;
  double x[] = {1.0, 2.0}

void proof_harness_adaline_fit() {
  struct adaline ada = new_adaline(2, 0.1);
  const int N = 2;
  double **X = (double **)malloc(N * sizeof(double *));
  assert(X != NULL);
  for (int i = 0; i < N; i++) {
    X[i] = (double *)malloc(2 * sizeof(double));
    assert(X[i] != NULL);
  }

void proof_harness_adaline_fit_sample() {
  struct adaline ada;
  ada.eta = 0.1;
  ada.num_weights = 3;
  ada.weights = (double *)malloc(ada.num_weights * sizeof(double));
  assert(ada.weights != NULL);
  ada.weights[0] = 1.0;
  ada.weights[1] = 2.0;
  ada.weights[2] = 3.0;
  double x[] = {1.0, 2.0}

void proof_harness_delete_adaline() {
  struct adaline *ada = NULL;
  delete_adaline(ada);
}

void proof_harness_new_adaline() {
  int num_features;
  double eta;
  __CPROVER_assume(eta > 0.f && eta < 1.f);
  __CPROVER_assume(num_features > 0);
  struct adaline ada = new_adaline(num_features, eta);
  assert(ada.eta == eta);
  assert(ada.num_weights == num_features + 1);
  assert(ada.weights != NULL);
  for (int i = 0; i < ada.num_weights; i++) {
    assert(ada.weights[i] == 1.f);
  }

void proof_harness_test3() {
  double eta = 0.1;
  test3(eta);
}

void proof_harness_test2() {
  double eta = 0.1;
  test2(eta);
}

void proof_harness_adaline_activation() {
  double x;
  __CPROVER_assume(x >= 0);
  assert(adaline_activation(x) == 1);
  __CPROVER_assume(x < 0);
  assert(adaline_activation(x) == -1);
}

