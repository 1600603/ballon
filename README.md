# RECUPERAR DO GIT #

1. Criar diretórios "balloon"
2. Clonar repositório dentro deste repositórios: git clone https://1600603@github.com/1600603/ballon.git
3. criar outra pasta ("balloo2", por exemplo) em separado e fazer cocos new:
4. cocos new soccer -p com.riversgames.balloon -l cpp --portrait
5. copiar arquivos gerados neste novo diretório na pasta do repositório criado "balloon", com exceção da pasta "Classes" e "Resources" e do arquivo "CMakeLists.txt". Obs: não sobrescrever nenhum arquivo, caso solicitado.
6. apagar a pasta "balloon2"
7. instalar todos plugins do sdkbox: sdkbox import...


# ENVIAR MUDANÇAS PARA REPOSITÓRIO #

1. git add .
2. git commit -m "<MSG>"
3. git push origin master

# RECUPERAR ATUALIZAÇÕES DO REPOSITÓRIO #

1. git pull

# COMPILAR ANDROID #

cocos compile -p android --android-studio -m release -o ./release/android

# USAR COMANDOS SDKBOX LINUX #

export SDKBOX="../../.sdkbox/bin/sdkbox"


 # O QUE É ALTERADO ANDROID STUDIO: #

 1. app/res/values/strings.xml - muda o nome do app
 2. app/res/mipmap* icones
 3. para sdkboxplay:
 You should replace your app_id in AndroidManifest.xml

replace following line
<meta-data android:name="com.google.android.gms.games.APP_ID" android:value="_your_app_id_" />
with

<meta-data android:name="com.google.android.gms.games.APP_ID" android:value="@string/app_id" />
add following line to <Your Project>\proj.android\res\values\strings.xml
<string name="app_id">_your_app_id_</string>



 # ALTERACOES IPHONE #

 para sdkbox:
em info.plist
 <key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>

4. retirar : SEND_SMS do AndroidManifest, após instalar plugin sdkbox share


# UBUNTU: resolver problema libfmod.so

Ir até o diretório do cocos (instalação) via terminal e digitar este comando

sudo cp ./external/linux-specific/fmod/prebuilt/64-bit/libfmodL.so /usr/lib/ | sudo cp ./external/linux-specific/fmod/prebuilt/64-bit/libfmod.so /usr/lib/ | sudo ln -s /usr/lib/libfmod.so /usr/lib/libfmod.so.6 | sudo ln -s /usr/lib/libfmodL.so /usr/lib/libfmod.soL.6
