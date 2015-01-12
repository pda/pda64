pda64.img: boot sign_boot_sector
	cp boot pda64.img
	./sign_boot_sector

boot: boot.s
	nasm -o boot boot.s

sign_boot_sector: sign_boot_sector.c
	clang -o sign_boot_sector sign_boot_sector.c

.PHONY: clean

clean:
	rm -f pda64.img boot_sector sign_boot_sector
