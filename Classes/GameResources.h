#ifndef __GAME_RESOURCES_H__
#define __GAME_RESOURCES_H__
#include <string>
/*-------------Loading------------------*/
const std::string LOADING_PLIST = "ui/loading.plist";
const std::string LOADING = "loading";
/*-------------Hero-----------------*/
const int HERO_TAG = 0;
/*-------------Elf-----------------*/
const std::string ELF_M_PLIST = "hero/elf_m.plist";
const std::string ELF_M_BODY_PLIST = "hero/elf_m_body.plist";
const std::string ELF_M_HIT = "elf_m_hit";
const std::string ELF_M_IDLE = "elf_m_idle";
const std::string ELF_M_RUN = "elf_m_run";

/*-----------Knight----------------*/
const std::string KNIGHT_M_PLIST = "hero/knight_m.plist";
const std::string KNIGHT_M_BODY_PLIST = "hero/knight_m_body.plist";
const std::string KNIGHT_M_HIT = "knight_m_hit";
const std::string KNIGHT_M_IDLE = "knight_m_idle";
const std::string KNIGHT_M_RUN = "knight_m_run";

/*-----------Lizard----------------*/
const std::string LIZARD_M_PLIST = "hero/lizard_m.plist";
const std::string LIZARD_M_BODY_PLIST = "hero/lizard_m_body.plist";
const std::string LIZARD_M_HIT = "lizard_m_hit";
const std::string LIZARD_M_IDLE = "lizard_m_idle";
const std::string LIZARD_M_RUN = "lizard_m_run";

/*-----------Wizard----------------*/
const std::string WIZARD_F_PLIST = "hero/wizard_f.plist";
const std::string WIZARD_F_BODY_PLIST = "hero/wizard_f_body.plist";
const std::string WIZARD_F_HIT = "wizard_f_hit";
const std::string WIZARD_F_IDLE = "wizard_f_idle";
const std::string WIZARD_F_RUN = "wizard_f_run";

/*-------------Weapon---------------*/
const std::string WEAPON_PLIST = "base_weapon/base_weapon.plist";
const std::string WEAPON_BODY_PLIST = "base_weapon/base_weapon_body.plist";
const std::string SWORD = "weapon_knight_sword";
const int PLAYER_ATTACK_TAG = 1;
const std::string SWORD_SLASH_PLIST = "base_weapon/SwordSlash.plist";
const std::string SWORD_SLASH_BODY = "base_weapon/SwordSlashBody.plist";
const std::string SWORD_SLASH = "sword_slash";

/*-------------SKELETON---------------*/
const int ENEMY_TAG = 2;
const std::string SKELETON_PLIST = "mobs/Skeleton.plist";
const std::string SKELETON_BODY_PLIST = "mobs/SkeletonBody.plist";
const std::string SKELETON_IDLE = "skeleton_idle";
const std::string SKELETON_RUN = "skeleton_run";
#endif // !__GAME_RESOURCES_H__

