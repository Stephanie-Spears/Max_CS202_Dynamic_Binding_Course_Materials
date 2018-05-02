//materials.h
//Max Smiley
//CS202 - program 2

#ifndef _MATERIALS_H
#define _MATERIALS_H

#include <iostream>
#include <cstring>
#include <cassert>

class Mat
{
	public:
		Mat();
		Mat(const Mat &to_copy);
		virtual ~Mat();

		Mat(char * in_name);
	
		virtual void display();
		virtual void complete();
		bool isComplete();

		virtual void edit() = 0;

	protected:
		char * name;
		bool completed;
};

class Reading: public Mat
{
	public:
		Reading();
		Reading(const Reading &to_copy);
		~Reading();

		Reading(char * in_name, char * in_author, int in_chapter, int in_page);

		void display();
		void edit();

	protected:
		char * author;
		int chapter;
		int page;
};

class Exercise: public Mat
{
	public:
		Exercise();
		Exercise(const Exercise &to_copy);
		~Exercise();

		Exercise(char * in_name);

		void display();

//		void unlink(int &i);
		Exercise * getNext();
		void setNext(Exercise * in_next);
		void edit();

	protected: 
		Exercise * next;
};

class Exercise_Set: public Mat
{
	public:
		Exercise_Set();
		Exercise_Set(const Exercise_Set &to_copy);
		~Exercise_Set();
	
		Exercise_Set(char * in_name);
	
		void add(Exercise * in_ex);

		void display();
//		void complete();
		void edit();

	protected:
		void recursive_delete(Exercise * node);
		void recursive_display(int count, Exercise * node);
		void recursive_edit(bool, int, int, Exercise * node);
		Exercise * head;
		int size;
};



class Lecture: public Mat
{
	public:
		Lecture();
		Lecture(const Lecture &to_copy);
		~Lecture();

		Lecture(char *, char *, const char *, int);

		void display();
		void edit();
	
	protected:
		char * presenter;
		char * medium;
		int numSlides;
};

#endif
