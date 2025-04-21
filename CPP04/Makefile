SUBDIRS =	ex00 ex01 ex02 ex03


all:
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done

#supprimer les objets et les programmes
fclean:
	@for dir in $(SUBDIRS); do \
		echo "Full cleaning $$dir..."; \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

.PHONY: clean fclean re all
