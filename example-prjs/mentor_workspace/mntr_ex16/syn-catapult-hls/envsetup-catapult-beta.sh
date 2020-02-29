#
# Export few environment variables to compile the example with Mentor's
# provided compiler and libraries.
#
# Usage:
# $ source envsetup.sh
#

# Base directory for CAD tools.
export CAD_PATH="/opt/cad"

# We do need Catapult HLS (high-level synthesis).
export PATH="${CAD_PATH}/catapult_beta/bin":${PATH}

# We do need Catapult Coverage.
export CCOV_HOME="${CAD_PATH}/ccov"
#export PATH="${CCOV_HOME}/bin:$PATH"

# Let's use the SystemC headers and library provided with Catapult HLS.
export SYSTEMC="${CAD_PATH}/catapult_beta/shared"

# We do need Mentor Modelsim (simulator).
export PATH="${CAD_PATH}/msim/modeltech/bin":$PATH

# We do need Vivado (logic synthesis).
source ${CAD_PATH}/vivado/settings64.sh

# We do need Synopsys Design Compiler (logic synthesis).
export PATH="${CAD_PATH}/syn/bin":$PATH

# We do need Cadence Genus (logic synthesis).
export PATH="${CAD_PATH}/genus/tools/bin":$PATH

# We do need Cadence Encounter RTL Compiler (logic synthesis).
export PATH="${CAD_PATH}/encounter/tools/bin":$PATH

# Makefiles and scripts from Catapult HLS may rely on this variable.
export MGC_HOME=${CAD_PATH}/catapult_beta

####
# We do need licensing for this example.
####

# Mentor Graphics
export LM_LICENSE_FILE=${LM_LICENSE_FILE}:"1720@bioeecad.ee.columbia.edu"
# Synopsys
export LM_LICENSE_FILE=${LM_LICENSE_FILE}:"27000@bioeecad.ee.columbia.edu"
# Cadence
export LM_LICENSE_FILE=${LM_LICENSE_FILE}:"5280@bioeecad.ee.columbia.edu"
# Xilinx
export XILINXD_LICENSE_FILE="2177@espdev.cs.columbia.edu"

export PS1="[catapult-beta] $PS1"
