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

Burn the SD card with image

Install in Orange Pi zero Plus H5

Turn on the orange pi

User root
Password orangepi

Turn off

Install in laptop with linux

Install gparted

Run the program and extended the memory

eject the SD card

Insert again in Orange pi

turn on
 
User root
Password orangepi

Run the terminal

`sudo apt-get update`

It will install updates




**Configurar para auto execução para mostrar as fotos**
1. Para instalar o pacote, use a seguinte linha:
`sudo apt-get install feh`

2. Agora, para testar se ele funciona, digite a seguinte linha. Substitua **/root/Desktop/Fotos** pelo diretório que contém toda a sua imagem.

`DISPLAY=:0.0 XAUTHORITY=/root/.Xauthority /usr/bin/feh --quiet --randomize --full-screen --reload 60 -Y --slideshow-delay 15.0 /root/Desktop/Fotos` &

Extra 3. Agora se quiser podemos usar tags curtas para tornar esse comando muito mais curto. Você pode ler mais sobre todas as bandeiras que você pode usar na página de manual feh, ou usar normalmente a de cima
`DISPLAY=:0.0 XAUTHORITY=/home/pi/.Xauthority /usr/bin/feh -q -p -Z -F -R  60 -Y -D 15.0 /root/Desktop/Fotos`  &


4. Agora, como você notará, isso trava a barra da linha de comando. Para corrigir isso, adicione o **&** após o comando e o script / processo será iniciado em segundo plano.

5. Então agora vamos armazenar isso em um arquivo de script simples. Dessa forma, você pode adicionar ou alterar posteriormente. Para fazer o arquivo, digite o seguinte comando:
`sudo nano /root/start-picture-frame.sh`

6. Aqui, digite as seguintes linhas.
`#!/bin/bash`
`DISPLAY=:0.0 XAUTHORITY=/root/.Xauthority /usr/bin/feh --quiet --randomize --full-screen --reload 60 -Y --slideshow-delay 15.0 /root/Desktop/Fotos`

Ctrl + X ->  Y  -> enter
7. Agora pronto, você pode testá-lo executando o seguinte comando.
`bash /root/start-picture-frame.sh`

**Configurando para iniciar junto com o SO**
Aplication --> Settings --> Session and Startup

Aba **Aplication Autostart**
Clicar em Add

Vai abrir uma janela
Name: Picture_frame
Command: `bash /root/start-picture-frame.sh`
clicar em OK

**Configurando para a tela não desligar**

Clicar em Add
Name: `dontsleep01`
Command:  `xset -dpms`
clicar em OK

Clicar em Add
Name: `dontsleep02` 
Command: `xset s off`
clicar em OK

<!--
No final do arquivo insira o comando que irá executar, por exemplo:
`bash /home/pi/start-picture-frame.sh &`       **&  é necessário**
-->

Salve e saia
Reiniciando, deverá executar automaticamente
Demora um puco até carregar as fotos 


Fontes 

https://linux.die.net/man/1/feh

https://pimylifeup.com/raspberry-pi-photo-frame/

https://cadernodelaboratorio.com.br/2015/06/10/inicializando-um-programa-automaticamente-no-raspberrypi/

https://www.vivaolinux.com.br/topico/XFCE/Como-fazer-pro-monitor-nao-desligar

audio
https://soundcloud.com/higorpatinho/sets/lista-de-musicas-sem-direitos

https://licensing.jamendo.com/pt/catalogo/instrumentos/popular/violino
