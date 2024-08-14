## Introduction

这个仓库旨在通过一系列例子说明如何使用 hls 和 xrt 对 FPGA-based 加速器进行设计，将其运行在 Alveo U280 板卡上，并通过 host code 与其交互，完成加速功能。

以下是对每个例子的简单介绍：



- **vadd：** 这是一个向量加的简单例子。通过运行这个例子，可以弄清基于 XRT 的加速器设计流程，同时简单了解如何通过 vitis_analyzer 获取一些性能数据，从而能够有依据地进行优化。
- **load_an_alveo_image：** 这个例子展示了如何将 xclbin 文件加载到 U280 板子上。通过这个例子，你可以熟悉 OpenCL 的简单用法。
- **simple_memory_alloc：** 这个例子展示了如何使用 U280 板卡加速向量加法。通过这个例子，你可以学会如何将 vadd hardware kernel 加载到板卡，以及如何与其交互以获得正确的运算结果（即如何书写 host code）。


Reference：https://github.com/Xilinx/Vitis-Tutorials
