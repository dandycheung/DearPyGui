#include "mvTooltip.h"
#include "mvApp.h"
#include "mvItemRegistry.h"
#include "mvImGuiThemeScope.h"
#include "mvFontScope.h"

namespace Marvel {

	void mvTooltip::InsertParser(std::map<std::string, mvPythonParser>* parsers)
	{

		mvPythonParser parser(mvPyDataType::UUID, "Undocumented function", { "Containers", "Widgets" });
		mvAppItem::AddCommonArgs(parser, (CommonParserArgs)(
			MV_PARSER_ARG_ID |
			MV_PARSER_ARG_SHOW)
		);

		parser.addArg<mvPyDataType::String>("parent");
		parser.finalize();

		parsers->insert({ s_command, parser });
	}

	mvTooltip::mvTooltip(mvUUID uuid)
		: 
		mvBoolPtrBase(uuid)
	{

		// has to be showed that way it can check for hovering
		// otherwise it will never show
		m_show = true;
		
	}

	void mvTooltip::draw(ImDrawList* drawlist, float x, float y)
	{
		if (ImGui::IsItemHovered())
		{
			mvImGuiThemeScope scope(this);
			mvFontScope fscope(this);
			ImGui::BeginTooltip();

			//we do this so that the children dont get the theme
			scope.cleanup();

			for (auto& item : m_children[1])
			{
				if (!item->preDraw())
					continue;

				item->draw(drawlist, ImGui::GetCursorPosX(), ImGui::GetCursorPosY());

				item->postDraw();
			}

			ImGui::EndTooltip();
		}

	}

	void mvTooltip::handleSpecificRequiredArgs(PyObject* dict)
	{
		if (!mvApp::GetApp()->getParsers()[s_command].verifyRequiredArguments(dict))
			return;

		for (int i = 0; i < PyTuple_Size(dict); i++)
		{
			PyObject* item = PyTuple_GetItem(dict, i);
			switch (i)
			{
			case 0:
				m_parent = ToUUID(item);
				break;

			default:
				break;
			}
		}
	}

}