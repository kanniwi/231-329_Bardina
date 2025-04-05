"""
URL configuration for lab1 project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""

"""urls.py - прописываются элементы url, обрабатываемые файлом бекенда, 
классы и методы, которые отвечают за обработку запросов к ним

Определяет маршруты (/historicalEvents/) и связывает их с представлениями (views.py)."""

from django.contrib import admin
from django.urls import path
from rest_framework import routers


from mainapp.views import historicalEventsViewSet


urlpatterns = [
    path('historicalEvents/', historicalEventsViewSet.as_view({'get': 'list', 'post': 'create'})),  

    path('historicalEvents/<int:pk>/', historicalEventsViewSet.as_view({
        'get': 'retrieve',
        'delete': 'destroy',
        'put': 'update',
        'patch': 'partial_update'
    })), 
]



