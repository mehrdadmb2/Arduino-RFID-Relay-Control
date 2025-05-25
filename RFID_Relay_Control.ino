#include <SPI.h>
#include <MFRC522.h>

// ——— پین‌ها ———
#define SS_PIN     10   // UNO SPI SS → RC522 SDA
#define RST_PIN    9    // RC522 RST
#define RELAY_PIN  7    // کنترل رله (Active HIGH)

MFRC522 mfrc522(SS_PIN, RST_PIN);

// لیست UIDهای مجاز (بدون دونقطه، حروف بزرگ)
const char* allowedUIDs[] = {
  "62768D4C",  // Mehrdad
  "C28A834C",  // Masoud
  "828C8D4C",  // Yas
  "42E18C4C"   // 4
};
const char* allowedNames[] = {
  "Mehrdad",
  "Masoud",
  "Yas",
  "4"
};
const int nTags = sizeof(allowedUIDs) / sizeof(allowedUIDs[0]);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // رله غیرفعال (LED خاموش)

  Serial.println(F(">> RFID + Relay (UNO)"));
}

void loop() {
  // منتظر کارت جدید
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // ساخت UID به صورت HEX
  String uid;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();
  Serial.print(F("Read UID: "));
  Serial.println(uid);

  // جستجوی نام
  String name = "Unknown";
  for (int i = 0; i < nTags; i++) {
    if (uid == allowedUIDs[i]) {
      name = allowedNames[i];
      break;
    }
  }
  Serial.print(F("Name: "));
  Serial.println(name);

  if (name != "Unknown") {
    // رله را روشن کن (با ورود HIGH)
    Serial.println(F("Access Granted → Relay ON"));
    digitalWrite(RELAY_PIN, HIGH);
    delay(1000);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println(F("Relay OFF"));
  } else {
    Serial.println(F("Access Denied"));
  }

  // منتظر دور شدن کارت
  while (mfrc522.PICC_IsNewCardPresent()) {
    delay(50);
  }
}
