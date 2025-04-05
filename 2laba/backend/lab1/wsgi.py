"""
WSGI config for lab1 project.

It exposes the WSGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/5.1/howto/deployment/wsgi/
"""

# asgi (Asynchronous Server Gateway Interface), wsgi (Web Server Gateway Interface) - нужны для связи 
# скриптов приложения с hhtp сервером (для работы с протоколом HTTP, т к питон сам автоматически 
# не добавляет первую строку, заголовки и тд)

import os

from django.core.wsgi import get_wsgi_application

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'lab1.settings')

application = get_wsgi_application()
