# WARNING: This file is just for testing 'validate'. Will be removed in the future.

validate <- function(idxs=NULL, N) {
  .Call('validate', idxs, N, PACKAGE='matrixStats')
}
