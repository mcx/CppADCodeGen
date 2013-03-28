# --------------------------------------------------------------------------
#  CppADCodeGen: C++ Algorithmic Differentiation with Source Code Generation:
#    Copyright (C) 2012 Ciengis
#
#  CppADCodeGen is distributed under multiple licenses:
#
#   - Common Public License Version 1.0 (CPL1), and
#   - GNU General Public License Version 2 (GPL2).
#
# CPL1 terms and conditions can be found in the file "epl-v10.txt", while
# terms and conditions for the GPL2 can be found in the file "gpl2.txt".
# ----------------------------------------------------------------------------
#
# Author: Joao Leal
#
# ----------------------------------------------------------------------------
# files to be installed
# ----------------------------------------------------------------------------
INSTALL( DIRECTORY "cppadcg/"
         DESTINATION ${install_include_location}
         FILES_MATCHING PATTERN "*.hpp")