# 计算机组成原理实验 — Xilinx 工程源码

> 贡献者：橘星奏 | 修读年份：2025 | 分数：94

本资料包含四川大学计算机组成原理课程 **5 个实验**的完整 Xilinx ISE 工程源码（Verilog HDL），使用 **Xilinx ISE Design Suite 14.7** 开发。

## 实验列表

| 序号 | 实验名称 | 工程文件夹 | 说明 |
|:---:|---------|-----------|------|
| 1 | 4 位加法器设计 | `adder_4bits` | 1 位全加器 + 4 位加法器顶层模块 |
| 2 | 多路选择器（MUX）设计 | `mux` | 2 选 1（32 位 / 5 位）+ 8 选 1（32 位） |
| 3 | 七段数码管显示驱动 | `Sseg7` | 段码映射、并串转换、16 进制转 8 段码 |
| 4 | 基于 IP 核的系统设计（IP2SOC） | `OExp03-IP2SOC` | 含 CPU、控制器、GPIO、RAM/ROM IP 核 |
| 5 | 数据路径设计（DataPath） | `OExp05-DataPath` | 32 位寄存器组、ALU 运算模块、IO 接口 |

## 获取源码

完整工程文件请前往原仓库下载：

**GitHub 仓库：[leafevans/scu-xilink_projects](https://github.com/leafevans/scu-xilink_projects)**

下载方式：
- 直接下载：点击仓库页面右上角 `Code` → `Download ZIP`
- Git 克隆：`git clone https://github.com/leafevans/scu-xilink_projects.git`

## 使用方法

1. 安装 **Xilinx ISE Design Suite 14.7**
2. 打开对应实验文件夹中的 `.xise` 工程文件
3. 综合设计：点击 `Synthesize - XST`
4. 仿真：点击 `Simulate Behavioral Model`

## 许可证

本项目采用 [CC BY-NC-SA 4.0](https://github.com/leafevans/scu-xilink_projects/blob/main/LICENSE) 许可协议。
