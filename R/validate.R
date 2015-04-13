############################################################################/**
# @RdocFunction validate
#
# @title "Validate indices"
#
# \description{
#   Computes validated positive indices from given indices.
# }
#
# \arguments{
#   \item{idxs}{A @integer @vector.}
#   \item{N}{The domain of indices.}
# }
#
# \value{
#   Returns a validated integers list indicating the indices.
# }
#
# @examples "../incl/validate.Rex"
#*/############################################################################
validate <- function(idxs=NULL, N) {
  .Call('validate', idxs, N, PACKAGE='matrixStats')
}
