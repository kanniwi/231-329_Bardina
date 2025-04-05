"""
ASGI config for lab1 project.

It exposes the ASGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/5.1/howto/deployment/asgi/
"""

# asgi (Asynchronous Server Gateway Interface), wsgi (Web Server Gateway Interface) - нужны для связи 
# скриптов приложения с hhtp сервером (для работы с протоколом HTTP, т к питон сам автоматически 
# не добавляет первую строку, заголовки и тд)

import os

from django.core.asgi import get_asgi_application

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'lab1.settings')

application = get_asgi_application()
