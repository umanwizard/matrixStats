library("matrixStats")

# - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Subsetted tests
# - - - - - - - - - - - - - - - - - - - - - - - - - - - -
source("utils/validateIndicesFramework.R")
x <- runif(6, min=-6, max=6)
storage.mode(x) <- "integer"
for (idxs in indexCases) {
  validateIndicesTestVector(x, idxs, ftest=meanOver, fsure=mean, na.rm=FALSE)
  validateIndicesTestVector(x, idxs, ftest=meanOver, fsure=mean, na.rm=TRUE)
}
