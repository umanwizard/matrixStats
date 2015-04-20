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
#   \item{idxs}{A @integer @vector. If @NULL, all indices are considered.}
#   \item{maxIdx}{The possible max index.}
# }
#
# \value{
#   Returns a validated integers list indicating the indices.
# }
#
# @examples "../incl/validate.Rex"
#*/############################################################################
validate <- function(idxs=NULL, maxIdx) {
  .Call('validate', idxs, maxIdx, PACKAGE='matrixStats')
}
