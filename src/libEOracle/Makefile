#------------------------------------------------------------------------------
include ../config/ProjectDef.mk
include ../config/RootDef.mk
#------------------------------------------------------------------------------

ORA           = $(OCCIHOME)
ORAINC        = $(ORA)/sdk/include
ORALIB        = $(ORA)

NAME          = EOracle

headers       = TOracleServerE2WFB.h TOracleServerE2W.h TOracleServerE2WX.h TOracleServerE2.h TOracleServerE.h TOracleServer.h TOracleResult.h TOracleRow.h

PROJECT_LIBS += -L$(OCCIHOME) -lclntsh -locci 
PROJECT_LIBS += -L$(FEDRA_ROOT)/lib -lScan -lEdb -lEbase -lEmath -lEphys -lvt -lEdr -lScan

INC_DIR      += -I$(ORAINC)
CXXFLAGS     += -I$(INC_DIR) -DNOTROOTCINT

#------------------------------------------------------------------------------
include ../config/TargetsDef.mk
#------------------------------------------------------------------------------
