pda64.img: write_boot_sector boot_sector
	cp boot_sector pda64.img
	./write_boot_sector

boot_sector: boot_sector.s
	nasm -o boot_sector boot_sector.s

write_boot_sector: write_boot_sector.c
	clang -o write_boot_sector write_boot_sector.c
