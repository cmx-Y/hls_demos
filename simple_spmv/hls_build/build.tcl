open_project -reset spmv_prj
set_top spmv
add_files -tb ../tb/spmv_test.cpp  -cflags "-I../src"
add_files     ../src/spmv.cpp    -cflags "-I../src"
open_solution "solution"
set_part {xcu280-fsvh2892-2L-e}
create_clock -period 3.33333333 -name default
config_flow -target vitis
csim_design
csynth_design
exit
