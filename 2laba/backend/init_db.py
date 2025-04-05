import os
import django
from fill_db import fill_database

os.environ.setdefault("DJANGO_SETTINGS_MODULE", "lab1.settings")
django.setup()

from django.contrib.auth.models import User
from mainapp.models import historicalEvents

# Создание суперпользователя, если он не существует
if not User.objects.filter(username="admin1").exists():
    User.objects.create_superuser("admin1", "admin@example.com", "adminpassword1")
    print("Создан суперпользователь admin1")

# historicalEvents.objects.all().delete()

# Добавление тестовых данных для исторических событий, если их нет
if not historicalEvents.objects.exists():
    fill_database()
    # historicalEvents.objects.create(
    # start_date="2025-01-01",
    # end_date="2025-12-31",
    # title="Великая война",
    # category="Война",
    # is_peaceful=False
    # )
    # historicalEvents.objects.create(
    #     start_date="2025-06-01",
    #     end_date="2025-06-30",
    #     title="Мирное соглашение",
    #     category="Мир",
    #     is_peaceful=True
    # )
    print("Добавлены тестовые данные для исторических событий")

