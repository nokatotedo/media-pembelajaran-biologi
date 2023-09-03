#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <DFPlayer_Mini_Mp3.h>

#define push1 23
#define push2 25
#define push3 27
#define push4 29
#define push5 31
#define push6 33
#define push7 35
#define push8 37
#define push9 39
#define push10 41
#define pushA 47
#define pushB 49
#define pushC 43
#define pushD 45
#define led1 24
#define led2 30
#define led3 36
#define led4 38
#define led5 42
#define led6 40
#define led7 34
#define led8 32
#define led9 28
#define led10 26
#define rfidSda A0
#define rfidRst 48
#define sinyalEsp 5
#define buzzer 6

LiquidCrystal_I2C lcd(0x27, 20, 4);
MFRC522 rfid(rfidSda, rfidRst);
SoftwareSerial serialmp3(3, 2);

String id;
int tekan, lamaValue, kunci, jawaban, jumlah, poin;
bool satu, dua, tiga, empat, lima, enam, tujuh, delapan, sembilan, sepuluh;
bool sebelas, duabelas, tigabelas, empatbelas, limabelas, enambelas, tujuhbelas, delapanbelas, sembilanbelas, duapuluh;
int sisawaktu;

void setup() {
  Serial.begin(9600);
  serialmp3.begin(9600);
  Serial3.begin(9600);
  SPI.begin(); rfid.PCD_Init();
  mp3_set_serial(serialmp3);
  mp3_set_volume(30);
  delay(10);
  for(int p = 23; p <= 49; p++) {
    pinMode(p, INPUT_PULLUP);
    p++;
  }
  for(int l = 24; l <= 42; l++) {
    pinMode(l, OUTPUT);
    l++;
  }
  pinMode(sinyalEsp, OUTPUT); pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH); delay(1000);
  digitalWrite(buzzer, LOW);
  lcd.init(); lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("      Belajar       ");
  lcd.setCursor(0, 1);
  lcd.print("       Organ        ");
  lcd.setCursor(0, 2);
  lcd.print("       Tubuh        ");
  lcd.setCursor(0, 3);
  lcd.print("      Manusia       ");

  randomSeed(analogRead(0));
  delay(5000);
  lcd.clear();
}

void loop() {
  if(tekan == 0) {
    lcd.setCursor(0, 0);
    lcd.print("1.Tekan Push Button ");
    lcd.setCursor(0, 1);
    lcd.print("  Untuk Belajar...  ");
    lcd.setCursor(0, 2);
    lcd.print("2.Scan Kartu RFID   ");
    lcd.setCursor(0, 3);
    lcd.print("  Untuk Ujian...    ");
  }
  
  if(tekan < 100) {
    pushOnLed(push1, led1, "Urin", 1); pushOffLed(push1, led1, 9);
    pushOnLed(push2, led2, "Ginjal", 2); pushOffLed(push2, led2, 18);
    pushOnLed(push3, led3, "Jantung", 3); pushOffLed(push3, led3, 16);
    pushOnLed(push4, led4, "Paru-paru", 4); pushOffLed(push4, led4, 13);
    pushOnLed(push5, led5, "Otak", 5); pushOffLed(push5, led5, 14);
    pushOnLed(push6, led6, "Tiroid", 6); pushOffLed(push6, led6, 11);
    pushOnLed(push7, led7, "Hati", 7); pushOffLed(push7, led7, 13);
    pushOnLed(push8, led8, "Lambung", 8); pushOffLed(push8, led8, 15);
    pushOnLed(push9, led9, "Pankreas", 9); pushOffLed(push9, led9, 16);
    pushOnLed(push10, led10, "Usus", 10); pushOffLed(push10, led10, 14);
  }

  if(tekan == 100) {
    int soal = random(1, 21);
    if((soal == 1) && (satu)) return;
    if((soal == 2) && (dua)) return;
    if((soal == 3) && (tiga)) return;
    if((soal == 4) && (empat)) return;
    if((soal == 5) && (lima)) return;
    if((soal == 6) && (enam)) return;
    if((soal == 7) && (tujuh)) return;
    if((soal == 8) && (delapan)) return;
    if((soal == 9) && (sembilan)) return;
    if((soal == 10) && (sepuluh)) return;
    if((soal == 11) && (sebelas)) return;
    if((soal == 12) && (duabelas)) return;
    if((soal == 13) && (tigabelas)) return;
    if((soal == 14) && (empatbelas)) return;
    if((soal == 15) && (limabelas)) return;
    if((soal == 16) && (enambelas)) return;
    if((soal == 17) && (tujuhbelas)) return;
    if((soal == 18) && (delapanbelas)) return;
    if((soal == 19) && (sembilanbelas)) return;
    if((soal == 20) && (duapuluh)) return;
    if(soal == 1) {
      kunci = 2;
      satu = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Pembuangan");
      lcd.setCursor(0, 1); lcd.print("B. Pernafasan");
      lcd.setCursor(0, 2); lcd.print("C. Pencernaan");
      lcd.setCursor(0, 3); lcd.print("D. Peredaran darah");
      mp3_play(11);
      delay(15500);
    } else if(soal == 2) {
      kunci = 1;
      dua = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Alveolus");
      lcd.setCursor(0, 1); lcd.print("B. Bronkus");
      lcd.setCursor(0, 2); lcd.print("C. Bronkiolus");
      lcd.setCursor(0, 3); lcd.print("D. Trakhea");
      mp3_play(12);
      delay(13500);
    } else if(soal == 3) {
      kunci = 2;
      tiga = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Jantung");
      lcd.setCursor(0, 1); lcd.print("B. Darah");
      lcd.setCursor(0, 2); lcd.print("C. Paru-paru");
      lcd.setCursor(0, 3); lcd.print("D. Bronkus");
      mp3_play(13);
      delay(14500);
    } else if(soal == 4) {
      kunci = 4;
      empat = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Mulut");
      lcd.setCursor(0, 1); lcd.print("B. Hidung");
      lcd.setCursor(0, 2); lcd.print("C. Kerongkongan");
      lcd.setCursor(0, 3); lcd.print("D. Paru-paru");
      mp3_play(14);
      delay(12500);
    } else if(soal == 5) {
      kunci = 1;
      lima = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Mulut");
      lcd.setCursor(0, 1); lcd.print("B. Kerongkongan");
      lcd.setCursor(0, 2); lcd.print("C. Lambung");
      lcd.setCursor(0, 3); lcd.print("D. Usus halus");
      mp3_play(15);
      delay(11500);
    } else if(soal == 6) {
      kunci = 2;
      enam = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Hidung");
      lcd.setCursor(0, 1); lcd.print("B. Mulut");
      lcd.setCursor(0, 2); lcd.print("C. Kerongkongan");
      lcd.setCursor(0, 3); lcd.print("D. Lambung");
      mp3_play(16);
      delay(11500);
    } else if(soal == 7) {
      kunci = 3;
      tujuh = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Lambung");
      lcd.setCursor(0, 1); lcd.print("B. Mulut");
      lcd.setCursor(0, 2); lcd.print("C. Anus");
      lcd.setCursor(0, 3); lcd.print("D. Pantat");
      mp3_play(17);
      delay(11500);
    } else if(soal == 8) {
      kunci = 3;
      delapan = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Serambi kanan");
      lcd.setCursor(0, 1); lcd.print("B. Bilik kanan");
      lcd.setCursor(0, 2); lcd.print("C. Bilik tengah");
      lcd.setCursor(0, 3); lcd.print("D. Bilik kiri");
      mp3_play(18);
      delay(13500);
    } else if(soal == 9) {
      kunci = 1;
      sembilan = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Diare");
      lcd.setCursor(0, 1); lcd.print("B. Leukimia");
      lcd.setCursor(0, 2); lcd.print("C. Maag");
      lcd.setCursor(0, 3); lcd.print("D. Radang usus buntu");
      mp3_play(19);
      delay(13500);
    } else if(soal == 10) {
      kunci = 2;
      sepuluh = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Pembuluh kapiler");
      lcd.setCursor(0, 1); lcd.print("B. Pembuluh nadi");
      lcd.setCursor(0, 2); lcd.print("C. Pembuluh vena");
      lcd.setCursor(0, 3); lcd.print("D. Pembuluh balik");
      mp3_play(20);
      delay(16500);
    } else if(soal == 11) {
      kunci = 2;
      sebelas = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Otak");
      lcd.setCursor(0, 1); lcd.print("B. Jantung");
      lcd.setCursor(0, 2); lcd.print("C. Paru-paru");
      lcd.setCursor(0, 3); lcd.print("D. Hati");
      mp3_play(24);
      delay(14500);
    } else if(soal == 12) {
      kunci = 1;
      duabelas = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Lambung");
      lcd.setCursor(0, 1); lcd.print("B. Tiroid");
      lcd.setCursor(0, 2); lcd.print("C. Ginjal");
      lcd.setCursor(0, 3); lcd.print("D. Pankreas");
      mp3_play(25);
      delay(13500);
    } else if(soal == 13) {
      kunci = 2;
      tigabelas = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Paru-paru");
      lcd.setCursor(0, 1); lcd.print("B. Hati");
      lcd.setCursor(0, 2); lcd.print("C. Otak");
      lcd.setCursor(0, 3); lcd.print("D. Usus");
      mp3_play(26);
      delay(14500);
    } else if(soal == 14) {
      kunci = 2;
      empatbelas = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Hati");
      lcd.setCursor(0, 1); lcd.print("B. Paru-paru");
      lcd.setCursor(0, 2); lcd.print("C. Ginjal");
      lcd.setCursor(0, 3); lcd.print("D. Lambung");
      mp3_play(27);
      delay(12500);
    } else if(soal == 15) {
      kunci = 3;
      limabelas = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Usus");
      lcd.setCursor(0, 1); lcd.print("B. Jantung");
      lcd.setCursor(0, 2); lcd.print("C. Tiroid");
      lcd.setCursor(0, 3); lcd.print("D. Pankreas");
      mp3_play(28);
      delay(12500);
    } else if(soal == 16) {
      kunci = 2;
      enambelas = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Pankreas");
      lcd.setCursor(0, 1); lcd.print("B. Ginjal");
      lcd.setCursor(0, 2); lcd.print("C. Hati");
      lcd.setCursor(0, 3); lcd.print("D. Otak");
      mp3_play(29);
      delay(11500);
    } else if(soal == 17) {
      kunci = 3;
      tujuhbelas = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Jantung");
      lcd.setCursor(0, 1); lcd.print("B. Paru-paru");
      lcd.setCursor(0, 2); lcd.print("C. Tiroid");
      lcd.setCursor(0, 3); lcd.print("D. Lambung");
      mp3_play(30);
      delay(12500);
    } else if(soal == 18) {
      kunci = 4;
      delapanbelas = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Jantung");
      lcd.setCursor(0, 1); lcd.print("B. Ginjal");
      lcd.setCursor(0, 2); lcd.print("C. Hati");
      lcd.setCursor(0, 3); lcd.print("D. Lambung");
      mp3_play(31);
      delay(13500);
    } else if(soal == 19) {
      kunci = 3;
      sembilanbelas = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Ginjal");
      lcd.setCursor(0, 1); lcd.print("B. Tiroid");
      lcd.setCursor(0, 2); lcd.print("C. Hati");
      lcd.setCursor(0, 3); lcd.print("D. Usus");
      mp3_play(32);
      delay(13500);
    } else if(soal == 20) {
      kunci = 3;
      duapuluh = true;
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("A. Paru-paru");
      lcd.setCursor(0, 1); lcd.print("B. Jantung");
      lcd.setCursor(0, 2); lcd.print("C. Usus");
      lcd.setCursor(0, 3); lcd.print("D. Pankreas");
      mp3_play(33);
      delay(14500);
    }
    int pencet = 0;
    int waktu = 0;
    int detik = 0;
    while(pencet == 0) {
      int jawaba = digitalRead(pushA);
      int jawabb = digitalRead(pushB);
      int jawabc = digitalRead(pushC);
      int jawabd = digitalRead(pushD);
      if(jawaba == 0) {
        jawaban = 1;
        pencet = 1;
      }
      if(jawabb == 0) {
        jawaban = 2;
        pencet = 1;
      }
      if(jawabc == 0) {
        jawaban = 3;
        pencet = 1;
      }
      if(jawabd == 0) {
        jawaban = 4;
        pencet = 1;
      }
      waktu++;
      sisawaktu++;
      Serial.println(waktu);
      if(waktu == 1000) {
        waktu = 0;
        detik++;
      }
      if(detik == 2) {
        jawaban = 5;
        pencet = 1;
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
      }
    }
    if(kunci == jawaban) {
      poin++;
    }
    Serial.println(sisawaktu);
    jumlah++;
    if(jumlah == 10) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    Terima Kasih    ");
      lcd.setCursor(0, 1);
      lcd.print("  Telah Ikut Ujian  ");
      lcd.setCursor(0, 2);
      lcd.print("       Nilai:       ");
      lcd.setCursor(0, 3);
      lcd.print("         ");
      if(poin == 10) {
        lcd.print(poin);
      } else {
        lcd.print("0");
        lcd.print(poin);
      }
      Serial3.println(poin);
      Serial3.println(sisawaktu);
      Serial3.println(id);
      mp3_play(21);
      delay(6500);
      lcd.clear();
      id = "";
      jumlah = 0;
      poin = 0;
      tekan = 0;
      satu = false; dua = false; tiga = false;
      empat = false; lima = false; enam = false;
      tujuh = false; delapan = false; sembilan = false;
      sepuluh = false;
      sebelas = false; duabelas = false; tigabelas = false;
      empatbelas = false; limabelas = false; enambelas = false;
      tujuhbelas = false; delapanbelas = false; sembilanbelas = false;
      duapuluh = false;
    }
  }

  if(tekan == 101) {
    if(!rfid.PICC_IsNewCardPresent()) return;
    if(!rfid.PICC_ReadCardSerial()) return;
    getID(rfid.uid.uidByte, rfid.uid.size);
    digitalWrite(buzzer, HIGH);
    if(id == " e3 39 1a b7") {
      tekan = 0;
      lcd.clear();
      delay(1000);
      digitalWrite(buzzer, LOW);
      digitalWrite(sinyalEsp, LOW);
    } else {
      Serial3.println(id);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
  }

  if(!rfid.PICC_IsNewCardPresent()) return;
  if(!rfid.PICC_ReadCardSerial()) return;
  getID(rfid.uid.uidByte, rfid.uid.size);
  digitalWrite(buzzer, HIGH);
  Serial.println(id);
  if((id == " e3 39 1a b7") && (tekan == 0)) {
    tekan = 101;
    lcd.clear();
    delay(1000);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("     Scan Kartu     ");
    lcd.setCursor(0, 2);
    lcd.print(" Daftar di Aplikasi ");
    mp3_play(22);
    digitalWrite(sinyalEsp, HIGH);
  } else if((id.length() > 2) && (tekan == 0)) {
    sisawaktu = 0;
    tekan = 100;
    digitalWrite(sinyalEsp, LOW);
    delay(1000);
    digitalWrite(buzzer, LOW);
  }
}

void pushOnLed(int push, int led, String nama, int suara) {
  int pushValue = digitalRead(push);
  if(pushValue == 0) {
    offLed();
    digitalWrite(led, HIGH);
    tekan = push+1;
    lamaValue = 0;
  }
  if((tekan == push+1) && (pushValue == 1)) {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("     Nama Organ     ");
    int position = (20-nama.length())/2;
    lcd.setCursor(position, 2);
    lcd.print(nama);
    mp3_play(suara);
    tekan--;
  }
}

void pushOffLed(int push, int led, int lama) {
  if(tekan == push) {
    if(lamaValue >= ((lama*38)-1)) {
      offLed();
      lcd.clear();
      tekan = 0;
    }
    lamaValue++;
    delay(1);
  }
}

void getID(byte *buffer, byte bufferSize) {
  id = "";
  for(byte i = 0; i < bufferSize; i++) {
    id.concat(String(buffer[i] < 0x10 ? " 0" : " "));
    id.concat(String(buffer[i], HEX));
  }
}

void offLed() {
  for(int l = 24; l <= 42; l++) {
    digitalWrite(l, LOW);
    l++;
  }
}