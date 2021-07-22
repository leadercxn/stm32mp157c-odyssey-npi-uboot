/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * npi_common.h
 *
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com
 * Copyright (c) 2019 Seeed Studio
 *
 */

#ifndef __CONFIG_NPI_COMMON_H__
#define __CONFIG_NPI_COMMON_H__

/**
 * support stm32mp157c-odyssey-npi som  boot-up  macro
 */
#define NPI_BOOT_SUPPORT

#define DEFAULT_MMC_ARGS \
	"mmcdev=0\0" \
	"mmcrootfstype=ext4 rootwait\0" \
	"finduuid=part uuid ${devtype} ${bootpart} uuid\0" \
	"args_mmc=run finduuid;setenv bootargs console=${console} " \
		"root=PARTUUID=${uuid} ro " \
		"rootfstype=${mmcrootfstype} " \
		"${cmdline}\0" \
	"args_mmc_old=setenv bootargs console=${console} " \
		"${optargs} " \
		"root=${oldroot} ro " \
		"rootfstype=${mmcrootfstype} " \
		"${cmdline}\0" \
	"args_mmc_uuid=setenv bootargs console=${console} " \
		"${optargs} " \
		"root=UUID=${uuid} ro " \
		"rootfstype=${mmcrootfstype} " \
		"${cmdline}\0" \
	"args_uenv_root=setenv bootargs console=${console} " \
		"${optargs} " \
		"root=${uenv_root} ro " \
		"rootfstype=${mmcrootfstype} " \
		"${cmdline}\0" \
	"args_netinstall=setenv bootargs ${netinstall_bootargs} " \
		"${optargs} " \
		"root=/dev/ram rw " \
		"${cmdline}\0" \
	"script=boot.scr\0" \
	"scriptfile=${script}\0" \
	"loadbootscript=load ${devtype} ${bootpart} ${loadaddr} ${scriptfile};\0" \
	"bootscript=echo Running bootscript from mmc${bootpart} ...; " \
		"source ${loadaddr}\0" \
	"bootenvfile=uEnv.txt\0" \
	"bootenv=uEnv.txt\0" \
	"importbootenv=echo Importing environment from ${devtype} ...; " \
		"env import -t ${loadaddr} ${filesize}\0" \
	"loadbootenv=load ${devtype} ${bootpart} ${loadaddr} ${bootenvfile}\0" \
	"loadimage=load ${devtype} ${bootpart} ${loadaddr} ${bootdir}/${bootfile}\0" \
	"loadrd=load ${devtype} ${bootpart} ${rdaddr} ${bootdir}/${rdfile}; setenv rdsize ${filesize}\0" \
	"loadfdt=echo loading ${fdtdir}/${fdtfile} ...; load ${devtype} ${bootpart} ${fdtaddr} ${fdtdir}/${fdtfile}\0" \
	"loadoverlay=echo uboot_overlays: loading ${uboot_overlay} ...; " \
		"load ${devtype} ${rootpart} ${rdaddr} ${uboot_overlay}; " \
		"fdt addr ${fdtaddr}; fdt resize ${fdt_buffer}; " \
		"fdt apply ${rdaddr}; fdt resize ${fdt_buffer};\0" \
	"virtualloadoverlay=if test -e ${devtype} ${rootpart} ${uboot_overlay}; then " \
				"run loadoverlay;" \
			"else " \
				"echo uboot_overlays: unable to find [${devtype} ${rootpart} ${uboot_overlay}]...;" \
			"fi;\0" \
	"capeloadoverlay=if test -e ${devtype} ${rootpart} ${uboot_overlay}; then " \
				"run loadoverlay;" \
			"else " \
				"echo uboot_overlays: unable to find [${devtype} ${rootpart} ${uboot_overlay}]...;" \
			"fi;\0" \
	"failumsboot=echo; echo FAILSAFE: U-Boot UMS (USB Mass Storage) enabled, media now available over the usb slave port ...; " \
		"ums 0 ${devtype} 1;\0" \
	"envboot=mmc dev ${mmcdev}; " \
		"if mmc rescan; then " \
			"echo SD/MMC found on device ${mmcdev};" \
			"if run loadbootscript; then " \
				"run bootscript;" \
			"else " \
				"if run loadbootenv; then " \
					"echo Loaded env from ${bootenvfile};" \
					"run importbootenv;" \
				"fi;" \
				"if test -n $uenvcmd; then " \
					"echo Running uenvcmd ...;" \
					"run uenvcmd;" \
				"fi;" \
			"fi;" \
		"fi;\0" \
	"mmcloados=run args_mmc; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if run loadfdt; then " \
				"if test -n ${uname_r}; then " \
					"${bootcmd} ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}; " \
				"else " \
					"${bootcmd} ${loadaddr} - ${fdtaddr}; " \
				"fi; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"${bootcmd}; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"${bootcmd}; " \
		"fi;\0" \
	"mmcboot=mmc dev ${mmcdev}; " \
		"setenv devnum ${mmcdev}; " \
		"setenv devtype mmc; " \
		"if mmc rescan; then " \
			"echo SD/MMC found on device ${mmcdev};" \
			"if run loadimage; then " \
				"if test ${boot_fit} -eq 1; then " \
					"run loadfit; " \
				"else " \
					"run mmcloados;" \
				"fi;" \
			"fi;" \
		"fi;\0"


#define NPI_BOOT \
	"boot=${devtype} dev ${mmcdev}; " \
		"echo npi-booting ....;"	\
		"if ${devtype} rescan; then " \
			"setenv bootpart ${mmcdev}:1; " \
			"if test -e ${devtype} ${bootpart} /etc/fstab; then " \
				"setenv mmcpart 1;" \
			"fi; " \
			"echo Checking for: /uEnv.txt ...;" \
			"if test -e ${devtype} ${bootpart} /uEnv.txt; then " \
				"if run loadbootenv; then " \
					"echo Loaded environment from /uEnv.txt;" \
					"run importbootenv;" \
				"fi;" \
				"echo Checking if uenvcmd is set ...;" \
				"if test -n ${uenvcmd}; then " \
					"echo Running uenvcmd ...;" \
					"run uenvcmd; setenv uenvcmd;" \
				"fi;" \
				"echo Checking if client_ip is set ...;" \
				"if test -n ${client_ip}; then " \
					"if test -n ${dtb}; then " \
						"setenv fdtfile ${dtb};" \
						"echo using ${fdtfile} ...;" \
					"fi;" \
					"if test -n ${uname_r}; then " \
						"echo Running nfsboot_uname_r ...;" \
						"run nfsboot_uname_r;" \
					"fi;" \
					"echo Running nfsboot ...;" \
					"run nfsboot;" \
				"fi;" \
			"fi; " \
			"echo Checking for: /${script} ...;" \
			"if test -e ${devtype} ${bootpart} /${script}; then " \
				"setenv scriptfile ${script};" \
				"run loadbootscript;" \
				"echo Loaded script from ${scriptfile};" \
				"run bootscript;" \
			"fi; " \
			"echo Checking for: /boot/${script} ...;" \
			"if test -e ${devtype} ${bootpart} /boot/${script}; then " \
				"setenv scriptfile /boot/${script};" \
				"run loadbootscript;" \
				"echo Loaded script from ${scriptfile};" \
				"run bootscript;" \
			"fi; " \
			"echo Checking for: /boot/uEnv.txt ...;" \
			"for i in 1 2 3 4 5 6 7 ; do " \
				"setenv mmcpart ${i};" \
				"setenv curpart ${mmcdev}:${mmcpart};" \
				"if test -e ${devtype} ${curpart} /uEnv.txt; then " \
					"setenv bootpart ${mmcdev}:${mmcpart};" \
					"echo after find uEnv.txt bootpart=${bootpart} mmcdev=${mmcdev} mmcpart=${mmcpart};"	\
					"load ${devtype} ${curpart} ${loadaddr} /uEnv.txt;" \
					"env import -t ${loadaddr} ${filesize};" \
					"echo Loaded environment from /uEnv.txt;" \
					"if test -n ${uenvcmd}; then " \
						"echo Running uenvcmd ...${uenvcmd};" \
						"run uenvcmd; setenv uenvcmd;" \
					"fi;" \
				"fi;" \
				"if test -e ${devtype} ${curpart} /bin/sh; then " \
					"setenv rootpart ${mmcdev}:${mmcpart};" \
					"if test -n ${dtb}; then " \
						"echo debug: [dtb=${dtb}] ... ;" \
						"setenv fdtfile ${dtb};" \
						"echo Using: dtb=${fdtfile} ...;" \
					"fi;" \
					"echo Checking if uname_r is set in /uEnv.txt...;" \
					"if test -n ${uname_r}; then " \
						"setenv oldroot /dev/mmcblk${mmcdev}p${mmcpart};" \
						"echo Running uname_boot ...;" \
						"run uname_boot;" \
					"fi;" \
				"fi;" \
			"done;" \
		"fi;\0" \

#define NPI_UNAME_BOOT \
	"uname_boot="\
		"echo npi-uname-booting ....bootpart=${bootpart};"	\
		"setenv bootdir /boot; " \
		"setenv bootfile vmlinuz-${uname_r}; " \
		"setenv bootcmd bootz; " \
		"if test -e ${devtype} ${bootpart} ${bootdir}/${bootfile}; then " \
			"true;" \
		"else " \
			"setenv bootdir ;" \
			"if test -e ${devtype} ${bootpart} ${bootdir}/${bootfile}; then " \
				"echo can find ${bootdir}/${bootfile};"	\
				"true;" \
			"else " \
				"setenv bootfile zImage; " \
				"if test -e ${devtype} ${bootpart} ${bootdir}/${bootfile}; then " \
					"echo can find ${bootdir}/${bootfile};"	\
					"true;" \
				"else " \
					"setenv bootfile uImage; " \
					"if test -e ${devtype} ${bootpart} ${bootdir}/${bootfile}; then " \
						"echo can find ${bootdir}/${bootfile};"	\
						"setenv bootcmd bootm; " \
					"fi;" \
				"fi;" \
			"fi;" \
		"fi;" \
		"if test -e ${devtype} ${bootpart} ${bootdir}/${bootfile}; then " \
			"echo loading ${bootdir}/${bootfile} ...; "\
			"run loadimage;" \
			"setenv fdtdir ${bootdir}/dtbs/${uname_r}; " \
			"echo debug: [enable_uboot_overlays=${enable_uboot_overlays}] ... ;" \
			"if test -n ${enable_uboot_overlays}; then " \
				"echo debug: [uboot_base_dtb=${uboot_base_dtb}] ... ;" \
				"if test -n ${uboot_base_dtb}; then " \
					"echo uboot_overlays: [uboot_base_dtb=${uboot_base_dtb}] ... ;" \
					"if test -e ${devtype} ${bootpart} ${fdtdir}/${uboot_base_dtb}; then " \
						"setenv fdtfile ${uboot_base_dtb};" \
						"echo uboot_overlays: Switching to: dtb=${fdtfile} ...;" \
					"fi;" \
				"fi;" \
			"fi;" \
			"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
				"run loadfdt;" \
			"else " \
				"setenv fdtdir /usr/lib/linux-image-${uname_r}; " \
				"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
					"run loadfdt;" \
				"else " \
					"setenv fdtdir /boot/dtbs; " \
					"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
						"run loadfdt;" \
					"else " \
						"setenv fdtdir /boot; " \
						"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
							"run loadfdt;" \
						"else " \
							"if test -e ${devtype} ${bootpart} ${fdtfile}; then " \
								"run loadfdt;" \
							"else " \
								"echo; echo unable to find [dtb=${fdtfile}] did you name it correctly? ...; " \
								"run failumsboot;" \
							"fi;" \
						"fi;" \
					"fi;" \
				"fi;" \
			"fi; " \
			"if test -n ${enable_uboot_overlays}; then " \
				"setenv fdt_buffer 0x60000;" \
				"if test -n ${uboot_fdt_buffer}; then " \
					"setenv fdt_buffer ${uboot_fdt_buffer};" \
				"fi;" \
				"echo uboot_overlays: [fdt_buffer=${fdt_buffer}] ... ;" \
				"if test -n ${uboot_silicon}; then " \
					"setenv uboot_overlay ${uboot_silicon}; " \
					"run virtualloadoverlay;" \
				"fi;" \
				"if test -n ${uboot_model}; then " \
					"setenv uboot_overlay ${uboot_model}; " \
					"run virtualloadoverlay;" \
				"fi;" \
				"if test -n ${uboot_overlay_addr0}; then " \
					"setenv uboot_overlay ${uboot_overlay_addr0}; " \
					"run capeloadoverlay;" \
				"fi;" \
				"if test -n ${uboot_overlay_addr1}; then " \
					"setenv uboot_overlay ${uboot_overlay_addr1}; " \
					"run capeloadoverlay;" \
				"fi;" \
				"if test -n ${uboot_overlay_addr2}; then " \
					"setenv uboot_overlay ${uboot_overlay_addr2}; " \
					"run capeloadoverlay;" \
				"fi;" \
				"if test -n ${uboot_overlay_addr3}; then " \
					"setenv uboot_overlay ${uboot_overlay_addr3}; " \
					"run capeloadoverlay;" \
				"fi;" \
				"if test -n ${uboot_overlay_addr4}; then " \
					"setenv uboot_overlay ${uboot_overlay_addr4}; " \
					"run capeloadoverlay;" \
				"fi;" \
				"if test -n ${uboot_overlay_addr5}; then " \
					"setenv uboot_overlay ${uboot_overlay_addr5}; " \
					"run capeloadoverlay;" \
				"fi;" \
				"if test -n ${uboot_overlay_addr6}; then " \
					"setenv uboot_overlay ${uboot_overlay_addr6}; " \
					"run capeloadoverlay;" \
				"fi;" \
				"if test -n ${uboot_overlay_addr7}; then " \
					"setenv uboot_overlay ${uboot_overlay_addr7}; " \
					"run capeloadoverlay;" \
				"fi;" \
			"else " \
				"echo uboot_overlays: add [enable_uboot_overlays=1] to /boot/uEnv.txt to enable...;" \
			"fi;" \
			"setenv rdfile initrd.img-${uname_r}; " \
			"if test -e ${devtype} ${bootpart} ${bootdir}/${rdfile}; then " \
				"echo loading ${bootdir}/${rdfile} ...; "\
				"run loadrd;" \
				"if test -n ${netinstall_enable}; then " \
					"run args_netinstall; run message;" \
					"echo debug: [${bootargs}] ... ;" \
					"echo debug: [${bootcmd} ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}] ... ;" \
					"${bootcmd} ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}; " \
				"fi;" \
				"if test -n ${uenv_root}; then " \
					"run args_uenv_root;" \
					"echo debug: [${bootargs}] ... ;" \
					"echo debug: [${bootcmd} ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}] ... ;" \
					"${bootcmd} ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}; " \
				"fi;" \
				"if test -n ${uuid}; then " \
					"run args_mmc_uuid;" \
					"echo debug: [${bootargs}] ... ;" \
					"echo debug: [${bootcmd} ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}] ... ;" \
					"${bootcmd} ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}; " \
				"fi;" \
				"run args_mmc_old;" \
				"echo debug: [${bootargs}] ... ;" \
				"echo debug: [${bootcmd} ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}] ... ;" \
				"${bootcmd} ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}; " \
			"else " \
				"if test -n ${uenv_root}; then " \
					"run args_uenv_root;" \
					"echo debug: [${bootargs}] ... ;" \
					"echo debug: [${bootcmd} ${loadaddr} - ${fdtaddr}] ... ;" \
					"${bootcmd} ${loadaddr} - ${fdtaddr}; " \
				"fi;" \
				"run args_mmc_old;" \
				"echo debug: [${bootargs}] ... ;" \
				"echo debug: [${bootcmd} ${loadaddr} - ${fdtaddr}] ... ;" \
				"${bootcmd} ${loadaddr} - ${fdtaddr}; " \
			"fi;" \
		"else " \
			"echo debug: file missing ${devtype} ${bootpart} ${bootdir}/${bootfile} zImage vmlinuz-${uname_r};" \
		"fi;\0" \

#endif//__CONFIG_NPI_COMMON_H__
