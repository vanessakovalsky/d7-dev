<?php
    
    class DemoEntityUnitTestCase extends DrupalWebTestCase {
        die(var_dump('arrive dans le fichier'));
        public static function getInfo() {
            return array(
                'name' => 'demo entity test case',
                'description' => 'Vérifier l\'existence de l\entité démo',
                'group' => 'Formation Dev Groupe'
                         );
        }
        
        public function setUp() {
            parent::setUp(array('demo_entity'));
        }
        
        public function testEntityDemo() {
            $entity_description = entity_get_info('demo');
            $this->assertEqual($entity_description['base table'],'demo');
            
        }
    }
