<?php
if(file_exists("BUILD/DISCO_F746NG/GCC_ARM/Projekt.bin")){
    unlink("BUILD/DISCO_F746NG/GCC_ARM/Projekt.bin");
}
$test = exec("mbed compile -t GCC_ARM");
echo $test."\n";

if(file_exists("BUILD/DISCO_F746NG/GCC_ARM/Projekt.bin")){
    echo "it's here";
}
copy("BUILD/DISCO_F746NG/GCC_ARM/Projekt.bin", "/run/media/musti/DIS_F746NG/Projekt.bin");

?>