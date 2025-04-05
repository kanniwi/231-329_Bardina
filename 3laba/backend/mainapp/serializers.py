from rest_framework import serializers
from .models import historicalEvents
# Преобразует JSON в объекты модели и наоборот.

class historicalEventsSerializer(serializers.ModelSerializer):   
    class Meta:
        model = historicalEvents
        fields = '__all__'
