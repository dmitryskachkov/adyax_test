<?php
/**
 * @file
 * Ctools content type.
 *
 */
$plugin = array(
  'title' => t('Vimeo content type plugin'),
  'description' => t('The output video in iframe.'),
  'render callback' => 'adyax_test_content_type_render',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function adyax_test_content_type_render($subtype, $conf, $args, $context) {
  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->addTag('random')
    ->range(0, 3)
    ->execute();

  $nodes = node_load_multiple(array_keys($entities['node']));
  $render = node_view_multiple($nodes, 'full');
  $block = new stdClass();
  $block->content = $render;
  return $block;
}