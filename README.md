# Coffee Machine Waitress

Automante your coffee machine using an ESP8266

## BEWARE, We are working with AC current, I won't be responsible of any possible consequences that could cause following this tutorial, please take care of yourself and if you're young try to follow it under the supervision of an adult.

Tools:

ESP8266-01 + Programmer adapter:

https://es.aliexpress.com/store/product/CH340-USB-to-ESP8266-Serial-ESP-01-ESP-01S-ESP01-ESP01S-Wireless-Wifi-Developent-Board-Module/1414081_32971337222.html?spm=a219c.search0604.3.126.2fce4134en1GRu&ws_ab_test=searchweb0_0,searchweb201602_8_10065_10068_10547_319_10891_317_10548_10696_10084_453_454_10083_10618_10307_10820_10821_10301_10303_537_536_10902_10059_10884_10887_321_322_10103,searchweb201603_58,ppcSwitch_0&algo_expid=d63043e0-c6e6-49e6-8a5e-8f5352092c85-20&algo_pvid=d63043e0-c6e6-49e6-8a5e-8f5352092c85

A 2 Relay optoisolated module:

https://es.aliexpress.com/store/product/12V-1-way-road-relay-module-supports-low-level-trigger-along-the-way-Development-board-With/2290106_32814727050.html?spm=a219c.search0604.3.118.148f1aa1delAqw&ws_ab_test=searchweb0_0,searchweb201602_8_10065_10068_10547_319_10891_317_10548_10696_10084_453_454_10083_10618_10307_10820_10821_10301_10303_537_536_10902_10059_10884_10887_321_322_10103,searchweb201603_58,ppcSwitch_0&algo_expid=6414720a-aafe-4401-b4ce-e676baf18b99-16&algo_pvid=6414720a-aafe-4401-b4ce-e676baf18b99

AC/DC:

220 AC -> 3.3V DC: https://es.aliexpress.com/item/5pcs-TSP-03-replace-HLK-PM03-AC-DC-220V-to-3-3V-Step-Down-Buck-Power/32715513609.html


220 AC -> 5V DC  : https://es.aliexpress.com/store/product/5PCS-TSP-05-replace-HLK-PM01-AC-DC-220V-to-5V-mini-power-supply-module-intelligent/1084082_32715485959.html?spm=a219c.search0604.3.16.467e596dsdVXOQ&ws_ab_test=searchweb0_0,searchweb201602_8_10065_10068_10547_319_10891_317_10548_10696_10084_453_454_10083_10618_10307_10820_10821_10301_10303_537_536_10902_10059_10884_10887_321_322_10103,searchweb201603_58,ppcSwitch_0&algo_expid=50df7632-88d8-4e94-bbde-b5fb8a2994bb-2&algo_pvid=50df7632-88d8-4e94-bbde-b5fb8a2994bb


4 units of 3K3 Resistors

some female header pins:

https://www.alibaba.com/product-detail/10-20-30-pins-female-pin_60652080710.html

Soldering skills, and some protoshields.

Follow next manual to wire, ignore the PROGRAM_SW and RX Input part, we won't need it:

![GPIO pins](http://www.forward.com.au/pfod/ESP8266/GPIOpins/ESP8266_GPIO_OUTPUTS.jpg)

SOME IMAGES:

![button automation](https://raw.githubusercontent.com/warguns/coffee-waitress-esp8266/master/docs/img/IMG_20190318_122945.jpg?token=AC3KrB8lhKDIlpIfJalVazE7wUeSKOf1ks5cmlw2wA%3D%3D)
![button automation](https://raw.githubusercontent.com/warguns/coffee-waitress-esp8266/master/docs/img/IMG_20190318_123112.jpg?token=AC3KrHaMIZiPvnxL5Se_uH0nNu7aBBJcks5cmlx5wA%3D%3D)
![button automation](https://raw.githubusercontent.com/warguns/coffee-waitress-esp8266/master/docs/img/IMG_20190318_123202.jpg?token=AC3KrO66Bv6nmbQ7g6djjQ-oQzZla9qWks5cmlySwA%3D%3D)

MANY THANKS TO:

Forward, for the schemas http://www.forward.com.au/pfod/ESP8266/GPIOpins/ESP8266_01_pin_magic.html
Andreas Spiess, it's swiss accent, and of course it's awesome youtube channel: https://www.youtube.com/channel/UCu7_D0o48KbfhpEohoP7YSQ/featured
