
XOS = vadd.xo
BOARD_CONFIG := connectivity_u280.ini

PLATFORM := xilinx_u280_gen3x16_xdma_1_202211_1
TARGET := hw

VPPFLAGS := --platform $(PLATFORM) -t $(TARGET) -s -g
VPPLFLAGS := --config profile.ini
VPPLFLAGS += --config $(BOARD_CONFIG)

all: alveo_examples.xclbin

alveo_examples.xclbin: $(XOS) $(BOARD_CONFIG)
	v++ -l $(VPPFLAGS) $(VPPLFLAGS) -o $@ $(XOS) 

vadd.xo: vadd.cpp
	v++ --kernel vadd $(VPPFLAGS) -c -o $@ $<

clean:
	$(RM) -r *.xo _x .Xil sd_card *.xclbin *.ltx *.log *.info *compile_summary* vitis_analyzer* *link_summary*