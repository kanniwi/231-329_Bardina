# Create your views here.
# Определяет ViewSet или APIView, который принимает и обрабатывает HTTP-запросы.
# Отвечает за бизнес-логику: получение данных, обновление, удаление и т. д.

from django.shortcuts import render


from django.conf import settings


import rest_framework
from rest_framework import  viewsets


from .models import historicalEvents
from .serializers import historicalEventsSerializer

#viewsets.ModelViewSet класс-представление (ViewSet) автоматически создаёт API с CRUD-операциями

class historicalEventsViewSet(viewsets.ModelViewSet):
    queryset = historicalEvents.objects.all() # Получаем все записи из БД
    serializer_class = historicalEventsSerializer # Определяем сериализатор
