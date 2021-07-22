/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2018 BayLibre, SAS
 * Copyright (c) 2018 MediaTek Inc.
 * Author: Fabien Parent <fparent@baylibre.com>
 */

#ifndef _DT_BINDINGS_CLK_MT8516_H
#define _DT_BINDINGS_CLK_MT8516_H


/* APMIXEDSYS */

#define CLK_APMIXED_ARMPLL	0
#define CLK_APMIXED_MAINPLL	1
#define CLK_APMIXED_UNIVPLL	2
#define CLK_APMIXED_MMPLL	3
#define CLK_APMIXED_APLL1	4
#define CLK_APMIXED_APLL2	5
#define CLK_APMIXED_NR_CLK	6

/* TOPCKGEN */

#define CLK_TOP_CLK_NULL	0
#define CLK_TOP_I2S_INFRA_BCK	1
#define CLK_TOP_MEMPLL		2
#define CLK_TOP_DMPLL		3
#define CLK_TOP_MAINPLL_D2	4
#define CLK_TOP_MAINPLL_D4	5
#define CLK_TOP_MAINPLL_D8	6
#define CLK_TOP_MAINPLL_D16	7
#define CLK_TOP_MAINPLL_D11	8
#define CLK_TOP_MAINPLL_D22	9
#define CLK_TOP_MAINPLL_D3	10
#define CLK_TOP_MAINPLL_D6	11
#define CLK_TOP_MAINPLL_D12	12
#define CLK_TOP_MAINPLL_D5	13
#define CLK_TOP_MAINPLL_D10	14
#define CLK_TOP_MAINPLL_D20	15
#define CLK_TOP_MAINPLL_D40	16
#define CLK_TOP_MAINPLL_D7	17
#define CLK_TOP_MAINPLL_D14	18
#define CLK_TOP_UNIVPLL_D2	19
#define CLK_TOP_UNIVPLL_D4	20
#define CLK_TOP_UNIVPLL_D8	21
#define CLK_TOP_UNIVPLL_D16	22
#define CLK_TOP_UNIVPLL_D3	23
#define CLK_TOP_UNIVPLL_D6	24
#define CLK_TOP_UNIVPLL_D12	25
#define CLK_TOP_UNIVPLL_D24	26
#define CLK_TOP_UNIVPLL_D5	27
#define CLK_TOP_UNIVPLL_D20	28
#define CLK_TOP_MMPLL380M	29
#define CLK_TOP_MMPLL_D2	30
#define CLK_TOP_MMPLL_200M	31
#define CLK_TOP_USB_PHY48M	32
#define CLK_TOP_APLL1		33
#define CLK_TOP_APLL1_D2	34
#define CLK_TOP_APLL1_D4	35
#define CLK_TOP_APLL1_D8	36
#define CLK_TOP_APLL2		37
#define CLK_TOP_APLL2_D2	38
#define CLK_TOP_APLL2_D4	39
#define CLK_TOP_APLL2_D8	40
#define CLK_TOP_CLK26M		41
#define CLK_TOP_CLK26M_D2	42
#define CLK_TOP_AHB_INFRA_D2	43
#define CLK_TOP_NFI1X		44
#define CLK_TOP_ETH_D2		45
#define CLK_TOP_UART0_SEL	46
#define CLK_TOP_GFMUX_EMI1X_SEL	47
#define CLK_TOP_EMI_DDRPHY_SEL	48
#define CLK_TOP_AHB_INFRA_SEL	49
#define CLK_TOP_CSW_MUX_MFG_SEL	50
#define CLK_TOP_MSDC0_SEL	51
#define CLK_TOP_PWM_MM_SEL	52
#define CLK_TOP_UART1_SEL	53
#define CLK_TOP_MSDC1_SEL	54
#define CLK_TOP_SPM_52M_SEL	55
#define CLK_TOP_PMICSPI_SEL	56
#define CLK_TOP_QAXI_AUD26M_SEL	57
#define CLK_TOP_AUD_INTBUS_SEL	58
#define CLK_TOP_NFI2X_PAD_SEL	59
#define CLK_TOP_NFI1X_PAD_SEL	60
#define CLK_TOP_MFG_MM_SEL	61
#define CLK_TOP_DDRPHYCFG_SEL	62
#define CLK_TOP_USB_78M_SEL	63
#define CLK_TOP_SPINOR_SEL	64
#define CLK_TOP_MSDC2_SEL	65
#define CLK_TOP_ETH_SEL		66
#define CLK_TOP_AXI_MFG_IN_SEL	67
#define CLK_TOP_SLOW_MFG_SEL	68
#define CLK_TOP_AUD1_SEL	69
#define CLK_TOP_AUD2_SEL	70
#define CLK_TOP_AUD_ENGEN1_SEL	71
#define CLK_TOP_AUD_ENGEN2_SEL	72
#define CLK_TOP_I2C_SEL		73
#define CLK_TOP_AUD_I2S0_M_SEL	74
#define CLK_TOP_AUD_I2S1_M_SEL	75
#define CLK_TOP_AUD_I2S2_M_SEL	76
#define CLK_TOP_AUD_I2S3_M_SEL	77
#define CLK_TOP_AUD_I2S4_M_SEL	78
#define CLK_TOP_AUD_I2S5_M_SEL	79
#define CLK_TOP_AUD_SPDIF_B_SEL	80
#define CLK_TOP_PWM_SEL		81
#define CLK_TOP_SPI_SEL		82
#define CLK_TOP_AUD_SPDIFIN_SEL	83
#define CLK_TOP_UART2_SEL	84
#define CLK_TOP_BSI_SEL		85
#define CLK_TOP_DBG_ATCLK_SEL	86
#define CLK_TOP_CSW_NFIECC_SEL	87
#define CLK_TOP_NFIECC_SEL	88
#define CLK_TOP_APLL12_CK_DIV0	89
#define CLK_TOP_APLL12_CK_DIV1	90
#define CLK_TOP_APLL12_CK_DIV2	91
#define CLK_TOP_APLL12_CK_DIV3	92
#define CLK_TOP_APLL12_CK_DIV4	93
#define CLK_TOP_APLL12_CK_DIV4B	94
#define CLK_TOP_APLL12_CK_DIV5	95
#define CLK_TOP_APLL12_CK_DIV5B	96
#define CLK_TOP_APLL12_CK_DIV6	97
#define CLK_TOP_NR_CLK		98

/* TOPCKGEN Gates */
#define CLK_TOP_PWM_MM		0
#define CLK_TOP_MFG_MM		1
#define CLK_TOP_SPM_52M		2
#define CLK_TOP_THEM		3
#define CLK_TOP_APDMA		4
#define CLK_TOP_I2C0		5
#define CLK_TOP_I2C1		6
#define CLK_TOP_AUXADC1		7
#define CLK_TOP_NFI		8
#define CLK_TOP_NFIECC		9
#define CLK_TOP_DEBUGSYS	10
#define CLK_TOP_PWM		11
#define CLK_TOP_UART0		12
#define CLK_TOP_UART1		13
#define CLK_TOP_BTIF		14
#define CLK_TOP_USB		15
#define CLK_TOP_FLASHIF_26M	16
#define CLK_TOP_AUXADC2		17
#define CLK_TOP_I2C2		18
#define CLK_TOP_MSDC0		19
#define CLK_TOP_MSDC1		20
#define CLK_TOP_NFI2X		21
#define CLK_TOP_PMICWRAP_AP	22
#define CLK_TOP_SEJ		23
#define CLK_TOP_MEMSLP_DLYER	24
#define CLK_TOP_SPI		25
#define CLK_TOP_APXGPT		26
#define CLK_TOP_AUDIO		27
#define CLK_TOP_PMICWRAP_MD	28
#define CLK_TOP_PMICWRAP_CONN	29
#define CLK_TOP_PMICWRAP_26M	30
#define CLK_TOP_AUX_ADC		31
#define CLK_TOP_AUX_TP		32
#define CLK_TOP_MSDC2		33
#define CLK_TOP_RBIST		34
#define CLK_TOP_NFI_BUS		35
#define CLK_TOP_GCE		36
#define CLK_TOP_TRNG		37
#define CLK_TOP_SEJ_13M		38
#define CLK_TOP_AES		39
#define CLK_TOP_PWM_B		40
#define CLK_TOP_PWM1_FB		41
#define CLK_TOP_PWM2_FB		42
#define CLK_TOP_PWM3_FB		43
#define CLK_TOP_PWM4_FB		44
#define CLK_TOP_PWM5_FB		45
#define CLK_TOP_USB_1P		46
#define CLK_TOP_FLASHIF_FREERUN	47
#define CLK_TOP_66M_ETH		48
#define CLK_TOP_133M_ETH	49
#define CLK_TOP_FETH_25M	50
#define CLK_TOP_FETH_50M	51
#define CLK_TOP_FLASHIF_AXI	52
#define CLK_TOP_USBIF		53
#define CLK_TOP_UART2		54
#define CLK_TOP_BSI		55
#define CLK_TOP_MSDC0_INFRA	56
#define CLK_TOP_MSDC1_INFRA	57
#define CLK_TOP_MSDC2_INFRA	58
#define CLK_TOP_USB_78M		59
#define CLK_TOP_RG_SPINOR	60
#define CLK_TOP_RG_MSDC2	61
#define CLK_TOP_RG_ETH		62
#define CLK_TOP_RG_AXI_MFG	63
#define CLK_TOP_RG_SLOW_MFG	64
#define CLK_TOP_RG_AUD1		65
#define CLK_TOP_RG_AUD2		66
#define CLK_TOP_RG_AUD_ENGEN1	67
#define CLK_TOP_RG_AUD_ENGEN2	68
#define CLK_TOP_RG_I2C		69
#define CLK_TOP_RG_PWM_INFRA	70
#define CLK_TOP_RG_AUD_SPDIF_IN	71
#define CLK_TOP_RG_UART2	72
#define CLK_TOP_RG_BSI		73
#define CLK_TOP_RG_DBG_ATCLK	74
#define CLK_TOP_RG_NFIECC	75
#define CLK_TOP_RG_APLL1_D2_EN	76
#define CLK_TOP_RG_APLL1_D4_EN	77
#define CLK_TOP_RG_APLL1_D8_EN	78
#define CLK_TOP_RG_APLL2_D2_EN	79
#define CLK_TOP_RG_APLL2_D4_EN	80
#define CLK_TOP_RG_APLL2_D8_EN	81
#define CLK_TOP_APLL12_DIV0	82
#define CLK_TOP_APLL12_DIV1	83
#define CLK_TOP_APLL12_DIV2	84
#define CLK_TOP_APLL12_DIV3	85
#define CLK_TOP_APLL12_DIV4	86
#define CLK_TOP_APLL12_DIV4B	87
#define CLK_TOP_APLL12_DIV5	88
#define CLK_TOP_APLL12_DIV5B	89
#define CLK_TOP_APLL12_DIV6	90

/* INFRACFG */

#define CLK_IFR_MUX1_SEL	0
#define CLK_IFR_ETH_25M_SEL	1
#define CLK_IFR_I2C0_SEL	2
#define CLK_IFR_I2C1_SEL	3
#define CLK_IFR_I2C2_SEL	4
#define CLK_IFR_NR_CLK		5

/* AUDIOTOP */

#define CLK_AUD_AFE		0
#define CLK_AUD_I2S		1
#define CLK_AUD_22M		2
#define CLK_AUD_24M		3
#define CLK_AUD_INTDIR		4
#define CLK_AUD_APLL2_TUNER	5
#define CLK_AUD_APLL_TUNER	6
#define CLK_AUD_HDMI		7
#define CLK_AUD_SPDF		8
#define CLK_AUD_ADC		9
#define CLK_AUD_DAC		10
#define CLK_AUD_DAC_PREDIS	11
#define CLK_AUD_TML		12
#define CLK_AUD_NR_CLK		13

/* MFGCFG */

#define CLK_MFG_BAXI		0
#define CLK_MFG_BMEM		1
#define CLK_MFG_BG3D		2
#define CLK_MFG_B26M		3
#define CLK_MFG_NR_CLK		4

#endif /* _DT_BINDINGS_CLK_MT8516_H */