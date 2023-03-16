# Tugas Besar 1 Mata Kuliah Pemrograman Berorientasi Objek IF2210
> Tugas Besar 1: Kompetisi Kartu ala Kerajaan Permen

## Anggota Kelompok
<table>
    <tr>
        <td colspan="3", align = "center"><center>Nama Kelompok: firSST</center></td>
    </tr>
    <tr>
        <td>No.</td>
        <td>Nama</td>
        <td>NIM</td>
    </tr>
    <tr>
        <td>1.</td>
        <td>Angger Ilham Amanullah</td>
        <td>13521001</td>
    </tr>
    <tr>
        <td>2.</td>
        <td>Jason Rivalino</td>
        <td>13521008</td>
    </tr>
    <tr>
        <td>3.</td>
        <td>Eunice Sarah Siregar</td>
        <td>13521013</td>
    </tr>
    <tr>
        <td>4.</td>
        <td>Muhhamad Syauqi Jannatan</td>
        <td>13521014</td>
    </tr>
    <tr>
        <td>5.</td>
        <td>Laila Bilbina Khoiru Nisa</td>
        <td>13521016</td>
    </tr>
    <tr>
        <td>6.</td>
        <td>Fahrian Afdholi</td>
        <td>13521031</td>
    </tr>
</table>

## Table of Contents
* [Deskripsi Singkat dan Alur Program](#deskripsi-singkat-dan-alur-program)
* [Struktur File](#struktur-file)
* [Requirements](#requirements)
* [Cara Menjalankan Program](#cara-menjalankan-program)
* [Acknowledgements](#acknowledgements)

## Deskripsi Singkat dan Alur Program
Dalam rangka merayakan pesta panen gula di kerajaan permen, akan diadakan kompetisi massal permainan kartu ala Kerajaan Permen. Ratu kerajaan permen ingin mencari pemain kartu terhebat di kerajaannya. Namun karena Ratu tidak bisa memantau permainan satu-persatu, kalian diminta untuk membuatkan sistem agar permainan dapat berjalan dengan adil. Bantulah ratu kerajaan permen untuk membuatkan permainan ala kerajaan permen.

1. Program menginisiasi 7 pemain. Dan secara bergiliran, player melakukan input  nama/nickname. Setiap player akan memiliki poin 0 pada mula-mula.
2. Poin hadiah awalnya akan dibuat sejumlah 64. Poin ini akan dinamis bertambah/berkurang tergantung perintah dari setiap pemain. Poin akan diberikan diujung ronde (ronde 6).
3. Program akan mengeluarkan sebuah menu dan memberikan 2 opsi untuk melakukan generasi urutan kartu pada deck untuk permainan ini. (opsi random atau opsi baca dari file (Untuk keperluan demo, sediakan opsi untuk memanipulasi urutan kartu pada deck dengan cara membaca teks dari sebuah file.))
4. Program akan memulai permainan ini dengan putaran permainan yang dijelaskan pada bagian Mekanisme di poin Putaran Permainan.
5. Dalam permainan, pemain dapat memilih sebuah perintah, daftar perintah sebagai berikut: (Double, Nest, Half, Ability)
6. Pada akhir permainan, poin hadiah akan diberikan ke pemenang. Dan pemain lain tidak mendapatkan poin. Permainan berakhir jika seorang pemain memiliki poin lebih dari sama dengan 2^32 poin.
7. Jika belum ada yang menyentuh 2^32 poin, maka permainan akan dilanjutkan dengan memulai dari ronde awal lagi. Kartu dikembalikan, pemain akan mendapat kartu kemampuan acak di ronde kedua dan seterusnya. Program juga akan mengeluarkan menu untuk memberikan opsi random/baca dari file untuk permainan selanjutnya.

## Struktur File
```bash
Tubes1_OOP                            
├─ src                                
│  ├─ class                           
│  │  ├─ Ability                      
│  │  │  ├─ AbilityCard.cpp           
│  │  │  └─ AbilityCard.hpp           
│  │  ├─ Card                         
│  │  │  ├─ Calculable                
│  │  │  │  ├─ Calculable.cpp         
│  │  │  │  └─ Calculable.hpp         
│  │  │  ├─ Card.cpp                  
│  │  │  └─ Card.hpp                  
│  │  ├─ Combination                  
│  │  │  ├─ Combination.cpp           
│  │  │  └─ Combination.hpp           
│  │  ├─ Exception                    
│  │  │  └─ Exception.hpp             
│  │  ├─ Player                       
│  │  │  ├─ PlayerAction              
│  │  │  │  ├─ AllAct                 
│  │  │  │  │  ├─ AbilityLessAct.cpp  
│  │  │  │  │  ├─ AbilityLessAct.hpp  
│  │  │  │  │  ├─ DoubleAct.cpp       
│  │  │  │  │  ├─ DoubleAct.hpp       
│  │  │  │  │  ├─ HalfAct.cpp         
│  │  │  │  │  ├─ HalfAct.hpp         
│  │  │  │  │  ├─ NextAct.cpp         
│  │  │  │  │  ├─ NextAct.hpp         
│  │  │  │  │  ├─ QuadrupleAct.cpp    
│  │  │  │  │  ├─ QuadrupleAct.hpp    
│  │  │  │  │  ├─ QuarterAct.cpp      
│  │  │  │  │  ├─ QuarterAct.hpp      
│  │  │  │  │  ├─ ReRollAct.cpp       
│  │  │  │  │  ├─ ReRollAct.hpp       
│  │  │  │  │  ├─ ReverseAct.cpp      
│  │  │  │  │  ├─ ReverseAct.hpp      
│  │  │  │  │  ├─ SwapAct.cpp         
│  │  │  │  │  ├─ SwapAct.hpp         
│  │  │  │  │  ├─ SwitchAct.cpp       
│  │  │  │  │  └─ SwitchAct.hpp       
│  │  │  │  ├─ Action.cpp             
│  │  │  │  └─ Action.hpp             
│  │  │  ├─ Player.cpp                
│  │  │  └─ Player.hpp                
│  │  ├─ Random                       
│  │  │  └─ Random.cpp                
│  │  ├─ SetGame                      
│  │  │  ├─ SetGame.cpp               
│  │  │  └─ SetGame.hpp               
│  │  ├─ Splash                       
│  │  │  ├─ Splash.cpp                
│  │  │  └─ Splash.hpp                
│  │  └─ Table                        
│  │     ├─ Table.cpp                 
│  │     └─ Table.hpp                 
│  ├─ config                          
│  │  └─ card.txt                     
│  ├─ main.cpp                        
│  └─ main.o                          
└─ README.md                          

 ```
 
## Requirements
Kebutuhan yang diperlukan untuk menjalankan program adalah sebagai berikut:
1. sistem operasi LINUX dengan G++ versi 11, 14 atau 17.

## Cara Menjalankan Program
Langkah-langkah proses menjalankan program adalah sebagai berikut:
1. Buka terminal
2. Masuk ke direktori Tubes1_OOP
3. Ketikkan perintah `g++ src/main.cpp src/class/*/*.cpp src/class/*/*/*.cpp src/class/*/*/*/*.cpp -o src/main.o` untuk melakukan kompilasi program

## Acknowledgements
- Tuhan Yang Maha Esa
- Dosen Mata Kuliah Pemrograman Berorientasi Objek IF2210
- Kakak-Kakak Asisten Mata Kuliah Pemrograman Berorientasi Objek IF2210
