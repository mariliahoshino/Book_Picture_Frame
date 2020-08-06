<!--
**Configurar do desligamento de tela**
1. Para desativar o apagamento da tela, abra o arquivo lightdm.conf .
`sudo nano /etc/lightdm/lightdm.conf`

2. Agora, aqui, adicione a seguinte linha em qualquer lugar abaixo da linha [SeatsDefaults] .
`xserver-command=X -s 0 –dpms`

3. Salve e saia pressionando ctrl + x e depois y .

4. Agora, reinicie o Pi e a tela não deverá mais se desligar após 10 minutos de inatividade. Para reiniciar, execute o seguinte:
`sudo reboot`
-->

### Dowload ISO image in store <br>
http://www.orangepi.org/downloadresources/orangepizeroplus/2020-01-16/orangepizeroplus16bb9cbd292207116405.html <br>

### Orange Pi zero Pins <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/orangepizeropins.jpg?raw=true"  height="300" > <br>


Burn the SD card with image <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/001_queima_cart%C3%A3o.png?raw=true"   height="300" >

Install in Orange Pi zero Plus H5

Turn on the orange pi

User **root** <br>
Password **orangepi** <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/002_primeiro_login20200730_181507.jpg?raw=true"   height="300" >


Turn off

Install in laptop with linux

Install **gparted** <br>
`sudo apt-get install gparted` <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/003instalar_gparted.png?raw=true"   height="300" >


Run the program and extended the memory <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/005_extender_mem20200621_204114.jpg?raw=true"   height="300" >

Eject the SD card
Insert again in Orange pi

Turn on
 
User **root** <br>
Password **orangepi** <br>
Run the terminal <br>
`sudo apt-get update` <br>
It will install updates <br>

**Configurar para auto execução para mostrar as fotos** <br>
1. Para instalar o pacote, use a seguinte linha: <br>
`sudo apt-get install feh` <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/008_install_feh20200730_183648.jpg?raw=true"   height="300" > <br>

2. Agora, para testar se ele funciona, digite a seguinte linha. Substitua **/root/Desktop/Fotos** pelo diretório que contém toda a sua imagem. <br>

`DISPLAY=:0.0 XAUTHORITY=/root/.Xauthority /usr/bin/feh --quiet --randomize --full-screen --reload 60 -Y --slideshow-delay 15.0 /root/Desktop/Fotos` &
<br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/009_testeone20200730_184838.jpg?raw=true"   height="300" > <br>

Extra 3. Agora se quiser podemos usar tags curtas para tornar esse comando muito mais curto. Você pode ler mais sobre todas as bandeiras que você pode usar na página de manual feh, ou usar normalmente a de cima <br>
`DISPLAY=:0.0 XAUTHORITY=/home/pi/.Xauthority /usr/bin/feh -q -p -Z -F -R  60 -Y -D 15.0 /root/Desktop/Fotos`  &

4. Agora, como você notará, isso trava a barra da linha de comando. Para corrigir isso, adicione o **&** após o comando e o script / processo será iniciado em segundo plano. <br>

5. Então agora vamos armazenar isso em um arquivo de script simples. Dessa forma, você pode adicionar ou alterar posteriormente. Para fazer o arquivo, digite o seguinte comando: <br>
`sudo nano /root/start-picture-frame.sh` <br>

6. Aqui, digite as seguintes linhas. <br>
`#!/bin/bash` <br>
`DISPLAY=:0.0 XAUTHORITY=/root/.Xauthority /usr/bin/feh --quiet --randomize --full-screen --reload 60 -Y --slideshow-delay 15.0 /root/Desktop/Fotos`
<br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/010_filesh_20200730_185613.jpg?raw=true"   height="300" > <br>

**Ctrl + X** ->  **Y**  -> **enter**

7. Agora pronto, você pode testá-lo executando o seguinte comando. <br>Irá rodar a exposição de fotos <br>
`bash /root/start-picture-frame.sh` <br>

**Configurando para iniciar junto com o SO** <br>
Aplication --> Settings --> Session and Startup
<br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/011_startup20200730_185910.jpg?raw=true"   height="300" >


Aba **Aplication Autostart** <br>
Clicar em Add <br>
Vai abrir uma janela <br>
Name: `Picture_frame` <br>
Command: `bash /root/start-picture-frame.sh` <br>
clicar em OK <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/012_20200730_190043.jpg?raw=true"   height="300" >


**Configurando para a tela não desligar** <br>
Clicar em Add <br>
Name: `dontsleep01` <br>
Command:  `xset -dpms` <br>
clicar em OK <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/013_20200730_190208.jpg?raw=true"   height="300" >

Clicar em Add <br>
Name: `dontsleep02` <br>
Command: `xset s off` <br>
clicar em OK <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/014_20200730_190251.jpg?raw=true"   height="300" >


Deverá ficar assim <br>
<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/015_20200730_190314.jpg?raw=true"   height="300" >

For play music it is necessary a player <br>
sudo apt-get install -y gnome-mplayer

<!--

<img src="  "   height="300" >
No final do arquivo insira o comando que irá executar, por exemplo:
`bash /home/pi/start-picture-frame.sh &`       **&  é necessário**
-->

Salve e saia
Reiniciando, deverá executar automaticamente
Demora um puco até carregar as fotos 

<img src="https://github.com/mariliahoshino/Book_Picture_Frame/blob/master/OrangePiZeroPlus/Pictures/016_20200730_190356.jpg?raw=true"   height="300" >

Fontes 

https://linux.die.net/man/1/feh

https://pimylifeup.com/raspberry-pi-photo-frame/

https://cadernodelaboratorio.com.br/2015/06/10/inicializando-um-programa-automaticamente-no-raspberrypi/

https://www.vivaolinux.com.br/topico/XFCE/Como-fazer-pro-monitor-nao-desligar

audio

https://www.youtube.com/audiolibrary/music

https://www.raspberrypi.org/forums/viewtopic.php?t=21616&fbclid=IwAR1H18MEUQLND09vzv9TD39KkpnH8swsrpc49G69jsIEuTi1e5dM8EzzcOg

<!--
https://soundcloud.com/higorpatinho/sets/lista-de-musicas-sem-direitos

https://licensing.jamendo.com/pt/catalogo/instrumentos/popular/violino
-->
