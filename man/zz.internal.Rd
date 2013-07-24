\name{zz.internal}
\alias{get.conf}
\alias{get.lib}
\title{ All Internal Functions }
\description{ All internal functions }
\usage{
  get.conf(arg, arch = '', package = "Rmpi")
  get.lib(arg, arch, package = "pbdPROF")
}
\arguments{
  \item{arg}{an argument to get from}
  \item{arch}{system architecture}
  \item{package}{package name}
}
\value{
  These are only for configuration at installation time if
  the flag \code{--enable-pbdPROF} is requested.
}
\references{
  Programming with Big Data in R Website:
  \url{http://r-pbd.org/}
}
\author{
  Wei-Chen Chen \email{wccsnow@gmail.com}.
}
\keyword{utilities}
