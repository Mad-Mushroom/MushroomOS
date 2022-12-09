cd ../gnu-efi/
rm -r ./x86_64/bootloader/*
make bootloader
cd ../kernel/
rm -r ./lib/*
make kernel
make buildimg
