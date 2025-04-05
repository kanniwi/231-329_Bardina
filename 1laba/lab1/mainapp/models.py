from django.db import models

# Create your models here.
# Определяет, как данные хранятся в базе

class historicalEvents(models.Model):
    start_date = models.DateField(null=True)   
    end_date = models.DateField(null=True)     
    title = models.CharField(max_length=32, null=True)   
    category = models.CharField(max_length=16, null=True)  
    is_peaceful = models.BooleanField(default=False)
    
    