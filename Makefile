write_boot_sector: write_boot_sector.c
	clang -o write_boot_sector write_boot_sector.c

pda64.img: write_boot_sector
	dd if=/dev/zero of=pda64.img bs=512 count=2880
	./write_boot_sector
