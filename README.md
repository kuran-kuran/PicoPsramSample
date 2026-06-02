# PicoPsramSample
RP2350マイコンでRSRAMを使いたい! 

## 対応基板

- WeAct RP2350B
-- psram_init(0)で初期化

- Pimoroni Pico Plus 2
-- psram_init(PIMORONI_PICO_PLUS2_PSRAM_CS_PIN)で初期化

- サイズとアドレス
#define PSRAM_BASE 0x11000000 
#define PSRAM_SIZE (8 * 1024 * 1024) 
psram.hppで定義している。 
PSRAM_SIZEがPSRAMサイズ、PSRAM_BASEがPSRAMの先頭アドレスになる 

## Windowsでのビルド
`>` md build  
`>` cd build  
`>` vcvars64  
`>` cmake .. -G "NMake Makefiles"  
または (Pythonのパスを指定する時)  
`>` cmake .. -G "NMake Makefiles" -DPython3_EXECUTABLE=D:\Apps\python3\python3.exe  
をしてから  
`>` nmake  

## Linuxでのビルド
$ mkdir build  
$ cd build  
$ cmake ..  
$ make  

