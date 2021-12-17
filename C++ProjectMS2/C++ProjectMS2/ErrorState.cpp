#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ErrorState.h"

namespace ama
{
	ErrorState::ErrorState(const char* errorMessage)
	{

		this->m_messageDisplay = nullptr;
		if (errorMessage == nullptr || errorMessage[0] == '\0')
		{
			this->m_messageDisplay = nullptr;
		}
		else
		{
			this->m_messageDisplay = new char[strlen(errorMessage) + 1];
			strcpy(m_messageDisplay, errorMessage);
		}
	}

	ErrorState::~ErrorState()
	{
		delete[] this->m_messageDisplay;
		this->m_messageDisplay = nullptr;
	}

	ErrorState::operator bool() const
	{
		if (m_messageDisplay != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	ErrorState& ErrorState::operator=(const char* pText)
	{
		delete[] this->m_messageDisplay;
		this->m_messageDisplay = nullptr;

		if (pText == nullptr || pText[0] == '\0')
		{
			this->m_messageDisplay = nullptr;
		}
		else
		{
			this->m_messageDisplay = new char[strlen(pText) + 1];
			strcpy(m_messageDisplay, pText);
		}

		return *this;
	}

	void ErrorState::message(const char* pText)
	{
		delete[] this->m_messageDisplay;
		this->m_messageDisplay = nullptr;

		*this = pText;
	}

	const char* ErrorState::message() const
	{
		if (this->m_messageDisplay == nullptr)
		{
			return nullptr;
		}
		else
		{
			return this->m_messageDisplay;
		}
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState &error)
	{
		if (error.message() != nullptr)
		{
			os << error.message();
		}

		return os;
	}








}