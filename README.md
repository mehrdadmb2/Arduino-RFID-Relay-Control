# 🔐 Arduino RFID Relay Control

> An Arduino UNO–based access control system using MFRC522 RFID and a relay module.  
> Grants access for authorized tags by toggling a relay for 1 second.

---

## 🚀 Features

- **RFID Authentication:** Reads 4-byte UID from MFRC522 cards.
- **Relay Control:** Activates a relay (Active HIGH) for 1 second on valid tag.
- **Configurable Tags:** Easily add or remove authorized UIDs in code.
- **Serial Debugging:** Prints UID and access status to Serial Monitor.

---

## 📦 Repository

**URL:**  
<https://github.com/mehrdadmb2/Arduino-RFID-Relay-Control>

---

## 🛠️ Hardware Components

| Component             | Model                 | Connection                         |
|-----------------------|-----------------------|------------------------------------|
| Arduino UNO R3        | —                     | USB or external 5 V                |
| MFRC522 RFID Module   | RC522                 | **SDA** → D10<br>**SCK** → D13<br>**MOSI** → D11<br>**MISO** → D12<br>**RST** → D9<br>**3.3V** & **GND** |
| Relay Module (5 V)    | 1-Channel Relay       | **IN** → D7 (active HIGH)<br>**VCC** → 5 V<br>**GND** → GND |
| RFID Card / Tag       | —                     | —                                  |
| Jumper Wires          | —                     | —                                  |

---

## 📋 Wiring Diagram

```

## Arduino UNO    ↔   MFRC522 RFID Module

5 V                3.3 V
GND                GND
D10 (SS)           SDA
D11 (MOSI)         MOSI
D12 (MISO)         MISO
D13 (SCK)          SCK
D9  (Digital)      RST

## Arduino UNO    ↔   Relay Module

D7 (Digital)       IN
5 V                 VCC
GND                GND

````

---

## ⚙️ Installation & Setup

1. **Clone the repo:**
   ```bash
   git clone https://github.com/mehrdadmb2/Arduino-RFID-Relay-Control.git
   cd Arduino-RFID-Relay-Control

2. **Open in Arduino IDE:**

   * File → Open → `RFID_Relay_Control.ino`
3. **Install Libraries:**

   * `MFRC522` by GithubCommunity / miguelbalboa
   * (via Sketch → Include Library → Manage Libraries → search & install)
4. **Configure Authorized UIDs:**

   ```cpp
   const char* allowedUIDs[] = {
     "62768D4C",  // Mehrdad
     "C28A834C",  // Masoud
     "828C8D4C",  // Yas
     "42E18C4C"   // 4
   };
   ```
5. **Upload to Arduino UNO:**

   * Select **Board**: Arduino UNO
   * Select correct **COM Port**
   * Click **Upload**

---

## 📖 Usage

* Power up your UNO.
* Open **Serial Monitor** at **9600 baud**.
* Present an authorized RFID tag:

  * **Success:** Relay clicks ON for 1 s, then OFF.
  * **Denied:** No relay activation, console prints “Access Denied.”

---

## 🛠 Customization

* **Relay Duration:** Change `delay(1000)` in code to adjust ON-time.
* **Active State:**

  * If your relay is **Active LOW**, invert `digitalWrite()` logic.
* **Add Tags:** Simply append new UIDs & names to `allowedUIDs` and `allowedNames`.

---

## 🤝 Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/new-feature`)
3. Commit your changes (`git commit -m 'Add new feature'`)
4. Push to the branch (`git push origin feature/new-feature`)
5. Open a Pull Request

---

## 📜 License

Distributed under the MIT License. See `LICENSE` for details.

---

## 🎉 Acknowledgments

* [Miguel Balboa’s MFRC522 Library](https://github.com/miguelbalboa/rfid)
* Arduino Community for inspiration and support

---

*Enjoy building secure, fun DIY RFID projects!* 🚪🔒 RFID + Relay = ❤️
