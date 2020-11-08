# Home-Security-IOT
## 1. İÇİNDEKİLER

- 1. İÇİNDEKİLER
- 2. EV GÜVENLİK SİSTEMLERİ İŞ MODELİ
- 3. İŞ FİKRİ
   - 3.1 İş Fikrinin Amacı
   - 3.2 İş Fikrinin Kapsamı
- 4. İŞ FİKRİ UYGULAMASI
   - 4.1 Kullanılan Teknolojileri
      - 4.1.1Kullanılan Donanım Teknolojileri
      - 4.1.2Kullanılan Yazılım Teknolojileri
   - 4.2 Uygulama Kabul ve Kısıtları
   - 4.3 Uygulama Hedefler ve Başarı Kriterleri
   - 4.4 Proje GELİŞTİRME SÜRECİ
      - 4.4.1Analiz
      - 4.4.2Tasarım
      - 4.4.3Kodlama
      - 4.4.4Test
- 5. DEĞERLENDİRME
- 6. KAYNAKÇA


## 2. EV GÜVENLİK SİSTEMLERİ İŞ MODELİ

![iotproje-16-8-2020](https://user-images.githubusercontent.com/72756431/98468108-febfa080-21e9-11eb-85b1-96290210bc8f.png)
```
Şekil 1 Business Model Canvas
```

## 3. İŞ FİKRİ

### 3.1 İş Fikrinin Amacı

İş fikrimizin amacı temel olarak düşük maliyetli ev durumsal kontrol – güvenlik sistemi
tasarlayıp satış, teknik servis, bakım, güncelleme ve yeni ürün geliştirme süreçlerini
kapsamaktadır.

### 3.2 İş Fikrinin Kapsamı

İş Fikrimiz sensörlerden aldığı verileri geliştirme kartları ile anlık olarak toplayıp
bulut platformlar üzerinden büyük veri oluşturan ve kullanıcıların cep telefonuna yüklü
mobil arayüze aktaran düşük maliyetli sistemleri kapsamaktadır.

## 4. İŞ FİKRİ UYGULAMASI

### 4.1 Kullanılan Teknolojileri

#### 4.1.1Kullanılan Donanım Teknolojileri

### 4.1.1.1 NodeMCU LoLin ESP8266 Geliştirme Kartı

LoLin, üzerinde NodeMCU firmware yüklü ESP8266 WiFi modül barındıran bir geliştirme
kartıdır. ESP8266 SDK'sı kullanılarak geliştirildiğinden, ekstradan bir mikrokontrolcüye
ihtiyaç duymadan GPIO, PWM, IIC, 1-Wire ve ADC bağlantılarını destekler. Üzerinde CH
USB - Seri dönüştürücü entegre bulunur.

### 4.1.1.2 Arduino UNO R

Arduino ailesinin, atmega328 mikrokontrolörüne sahip bir üyesidir. 14 dijital 6 analog
pine sahiptir.

### 4.1.1.3 Yağmur Sensörü

Birbirine paralel olarak çekilmiş iletken hatların su ile teması sonucu sensör çıkış
pininde analog bir değer okunabilmektedir. Hem analog hem digital çıkış vermektedir. 5 V ile
çalışır.

### 4.1.1.4 MQ- 9 Yanıcı Gaz Sensörü

Bu yarı iletken gaz sensörü, ortanda 100 ila 10.000 ppm yanıcı gaz konsantrasyon ve 10
ila 10.000 ppm Karbon Monoksit (CO) varlığını algılar. Hem analog hem digital çıkış
vermektedir. 5 V ile çalışır.

### 4.1.1.5 LM35DZ Sıcaklık Sensörü

Uygun maliyetli yüksek kaliteli sıcaklık sensörüdür. Analog çıkış verir. -55 ile 150
derece arasında ölçüm yapabilir. 10mV/derece hassasiyete sahiptir.


#### 4.1.2Kullanılan Yazılım Teknolojileri

### 4.1.2.1 ThingSpeak

Ardunio, Raspberry Pi gibi gömülü sistemlerden anlık olarak veri alıp gönderebilme bu
veriler ile grafiksel sunum, olay programlama, uyarı/alarm oluşturmaya yarayan ücretsiz
olarak kullanılabilen bir bulut platformudur.

### 4.1.2.2 Blynk

Ardunio, Raspberry Pi gibi gömülü sistemlerin cep telefonu tablet gibi mobil cihazlar
arasında haberleşmesini, kontrol ve anlık olarak veri alışverişini sağlayan ücretsiz ve
programlama bilgisine ihtiyaç duyulmadan kullanılabilen bir bulut platformudur.

### 4.2 Uygulama Kabul ve Kısıtları

- Ocak sensörü 40 değerinin üzeri veri göndermesi ocağın açık olduğu anlamına
    gelmektedir.
- Su sensörü 800 değerinin altına düştüğünde sensör ile su teması olduğu anlamına
    gelmektedir. Değer ne kadar düşerse o kadar fazla su teması olduğu 200’lü
    değerlerde sensörün komple su ile kaplandığı anlamına gelmektedir.
- Gaz sensörü 0 – 150 değerleri arasında ortamda yanıcı gaz olmadığı 400 – 1000
    arasında ortamda değer ile orantılı gaz olduğu anlamına gelmektedir.

### 4.3 Uygulama Hedefler ve Başarı Kriterleri

- Kolay kurulum
- Ucuz maliyet
- Müşteri memnuniyeti
- Sistemin kararlı çalışması

### 4.4 Proje GELİŞTİRME SÜRECİ

- Analiz
- Tasarım
- Kodlama
- Test

![NicePng_water-fall-png_863932](https://user-images.githubusercontent.com/72756431/98467287-88b93a80-21e5-11eb-93cc-c93b86e93e9f.png)
```
_Şekil 2 Proje Geliştirme Süreçleri_
```

#### 4.4.1Analiz

Sistemimiz internete çıkışı nodemcu ile yapacağız. Nodemcu tek analog portuna sahip
olduğu için sensörlerden verileri Arduino Uno ile okuyup software seri haberleşme ile
Nodemcu cihazımıza göndereceğiz. Nodemcu cihazımıza gelen verileri belirli aralıklarla
thingspeak ve blynk’e göndereceğiz.

#### 4.4.2Tasarım

![Başlıksız Diyagram ](https://user-images.githubusercontent.com/72756431/98468216-860d1400-21ea-11eb-933b-ebdf3b05b9a1.png)

```
Şekil 3 Yazılım Tasarımı
```
![Untitled Sketch_bb](https://user-images.githubusercontent.com/72756431/98468224-90c7a900-21ea-11eb-9a7a-f73b91bc9502.png)

```
Şekil 4 Donanım Tasarımı
```

#### 4.4.3Kodlama

![node1](https://user-images.githubusercontent.com/72756431/98468249-b48aef00-21ea-11eb-8bd8-15cadbd85879.png)

```
Şekil 5 NodeMCU Kodu
```
![arduinokod](https://user-images.githubusercontent.com/72756431/98468256-be145700-21ea-11eb-81c4-53b8f1de442c.png)

```
Şekil 6 Arduino Kodu
```

#### 4.4.4Test

![thingspeak](https://user-images.githubusercontent.com/72756431/98468311-fb78e480-21ea-11eb-9443-844e1217a4f2.png)

```
Şekil 7 ThingSpeak Arayüzü
```


![Screenshot_20200816-145831144](https://user-images.githubusercontent.com/72756431/98468273-d5534480-21ea-11eb-8189-3aaaabaa350f.jpg)
```
Şekil 8 Bylnk Arayüzü
```

## 5. DEĞERLENDİRME

Test sürecinde sonunda projemizin istenildiği gibi çalıştığı anlık olarak kurulu olduğu
ortamın durumunu kullanıcıya ve bulut platformuna doğru şekilde aktardığı görülmüştür. İş
fikrimiz doğal olarak büyük veri üretmektedir ama faydalı işlenebilecek bir büyük veri
üretmemektedir.

## 6. KAYNAKÇA

- https://community.thingspeak.com/tutorials/
- [http://help.blynk.cc/en/articles/512061-what-is-virtual-pins](http://help.blynk.cc/en/articles/512061-what-is-virtual-pins)
- https://stackoverflow.com/questions/55592575/serial-communication-between-arduino-
    and-nodemcu
- https://www.arduino.cc/en/Reference/SoftwareSerial


