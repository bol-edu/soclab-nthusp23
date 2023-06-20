# Run Xilinx Vivado Simulation (XSIM) of GCD Design

## Toolchain Prerequisites
* [Ubuntu 20.04+](https://releases.ubuntu.com/focal/)
* [Xilinx Vitis 2022.1](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/2022-1.html) (builtin XSIM and Vivado)
* [GTKWave v3.3.103](https://gtkwave.sourceforge.net/)

## Install GTKWave 
```console
$ sudo apt update
$ sudo apt install gtkwave -y
```

## Git Clone XSIM-GCD
```console
$ sudo apt install git -y
$ git clone https://github.com/bol-edu/soclab-nthusp23 ~/soclab-nthusp23
```

## Run GCD XSIM
```console
hls05@HLS05:~$ cd ~/soclab-nthusp23/lab/02.xsim-gcd
hls05@HLS05:~/soclab-nthusp23/lab/02.xsim-gcd$ ./run_xsim
INFO: [VRFC 10-2263] Analyzing Verilog file "/home/hls05/soclab-nthusp23/lab/02.xsim-gcd/seq_gcd.v" into library work
INFO: [VRFC 10-311] analyzing module seq_gcd
INFO: [VRFC 10-2263] Analyzing Verilog file "/home/hls05/soclab-nthusp23/lab/02.xsim-gcd/seq_gcd_tb.v" into library work
INFO: [VRFC 10-311] analyzing module seq_gcd_tb
Vivado Simulator v2022.1
Copyright 1986-1999, 2001-2022 Xilinx, Inc. All Rights Reserved.
Running: /opt/Xilinx/Vivado/2022.1/bin/unwrapped/lnx64.o/xelab -top seq_gcd_tb -snapshot seq_gcd_tb_elab
Multi-threading is on. Using 22 slave threads.
Starting static elaboration
Pass Through NonSizing Optimizer
Completed static elaboration
Starting simulation data flow analysis
Completed simulation data flow analysis
Time Resolution for simulation is 1ps
Compiling module work.seq_gcd
Compiling module work.seq_gcd_tb
Built simulation snapshot seq_gcd_tb_elab

****** xsim v2022.1 (64-bit)
  **** SW Build 3526262 on Mon Apr 18 15:47:01 MDT 2022
  **** IP Build 3524634 on Mon Apr 18 20:55:01 MDT 2022
    ** Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.

source xsim.dir/seq_gcd_tb_elab/xsim_script.tcl
# xsim {seq_gcd_tb_elab} -autoloadwcfg -runall
Time resolution is 1 ps
run -all
                 Result is correct:  GCD(  10312050,  29460792) -->: Expected =        138; Actual Result =        138
                 Result is correct:  GCD(1993627629,1177417612) -->: Expected =          7; Actual Result =          7
                 Result is correct:  GCD(2097015289,3812041926) -->: Expected =          1; Actual Result =          1
                 Result is correct:  GCD(1924134885,3151131255) -->: Expected =        135; Actual Result =        135
                 Result is correct:  GCD( 992211318, 512609597) -->: Expected =          1; Actual Result =          1
$stop called at time : 507500 ps : File "/home/hls05/soclab-nthusp23/lab/02.xsim-gcd/seq_gcd_tb.v" Line 85
exit
INFO: [Common 17-206] Exiting xsim at Tue Jun 20 10:57:49 2023...
```
## Use GTKWave to view simulated GCD waveform
```console
hls05@HLS05:~/soclab-nthusp23/lab/02.xsim-gcd$ gtkwave waveforms.gtkw
```
![gcd_waveforms](https://github.com/bol-edu/soclab-nthusp23/assets/98332019/9fffca84-7f76-4f4e-ba10-3e3c247c04ee)

## run_xsim Shell Script using Xilinx xvlog/xelab/xsim Command-line
```console
xvlog -f ./include.rtl.list.xsim seq_gcd_tb.v
xelab -top seq_gcd_tb -snapshot seq_gcd_tb_elab
xsim seq_gcd_tb_elab -R
```

## Add Hierarchical Verilog Designs to include.rtl.list.xsim
```
# design sources
./seq_gcd.v
```

## Reference
* [GTKWave 3.3 Wave Analyzer User's Guide](https://gtkwave.sourceforge.net/gtkwave.pdf)
