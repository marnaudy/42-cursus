#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(145, 137, "shrubbery creation") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm(145, 137, "shrubbery creation"), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other.getGradeSign(), other.getGradeExecute(), other.getName()),
		_target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	const_cast<std::string&>(_target) = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const {
	std::string outfile = _target + "_shrubbery";
	std::ofstream ofs;
	try {
		ofs.open(outfile.c_str());
		ofs.exceptions(std::ofstream::eofbit | std::ofstream::failbit | std::ofstream::badbit);
		ofs << "     .{{}}}}}}." << std::endl;
		ofs << "    {{{{{{(`)}}}." << std::endl;
		ofs << "   {{{(`)}}}}}}}}}" << std::endl;
		ofs << "  }}}}}}}}}{{(`){{{" << std::endl;
		ofs << "  }}}}{{{{(`)}}{{{{" << std::endl;
		ofs << " {{{(`)}}}}}}}{}}}}}" << std::endl;
		ofs << "{{{{{{{{(`)}}}}}}}}}}" << std::endl;
		ofs << "{{{{{{{}{{{{(`)}}}}}}" << std::endl;
		ofs << " {{{{{(`)   {{{{(`)}'" << std::endl;
		ofs << "  `\"\"'\" |   | \"'\"'`" << std::endl;
		ofs << "  (`)  /     \\" << std::endl;
		ofs << " ~~~~~~~~~~~~~~~~~~~" << std::endl;
		ofs.close();
	} catch (const std::exception &e) {
		std::cout << "Couldn't open " << _target;
		std::cout << "_shrubbery because : " << e.what() << std::endl;
	}
}
