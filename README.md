# ProjetoBixe
Repositório usado para o treinamento no GER

# Pasta Python
Usada para guardar o(s) arquivo(s) em python usado para enviar os dados
Detalhes do funcionamento do programa estão/deverão estar presentes em comentários no código

# Pasta ESP32
Usada para guardar o(s) arquivo(s) relacionado(s) ao ESP32
Detalhes sobre seu funcionamento estão/deverão estar presentes em comentários no código

# Instalações necessárias

Inicialmente, é necessário instalar o python. Aos usuários de windows, busque por Python na Microsoft Store e baixe aquele distribuido pela microsoft.


Além disso, é importante instalar a extennsão do python no VS code. Para isso, abra o menu de extensões do VS code (Ctrl+Shift+X) e digite "python". Instale a extensão "Python" e, caso não seja instalada automaticamente, instale as extensões "Python Debugger", "Pylance" e "Python Type Hint". 
Além disso, para facilitar a programação e a visualização do arquivo que irá conter o código do ESP32, instale também a extensão "Arduino", do distribuidor moozzyk.


Para o funcionamento do código em python, é necessário instalar somente a biblioteca "serial", já que a biblioteca "time" já vem pré instalada com o python. para isso, abra o terminal do VS code (Ctrl+Shift+') e coloque o seguinte comando:

pip install serial